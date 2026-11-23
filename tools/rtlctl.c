// Envía comandos al driver RTL8723DE vía IOKit (setProperties).
// Uso: rtlctl scan
//      rtlctl connect <ssid> <contraseña>
//      rtlctl disconnect
//      rtlctl rate <DESC_RATE: 0x00-0x0b>
//      rtlctl pmk <ssid> <contraseña>      imprime la PMK en hexadecimal
//      rtlctl autoconnect [archivo]        conecta con SSID y PMK guardados
// La contraseña no sale de este proceso: aquí se deriva la PMK (PBKDF2) y
// solo esos 32 bytes llegan al driver. El archivo de autoconnect (por defecto
// /etc/rtl8723de.conf, solo root) tiene el SSID en la línea 1 y la PMK en la 2.
#include <CommonCrypto/CommonKeyDerivation.h>
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DEFAULT_CONF "/etc/rtl8723de.conf"

static int derivePmk(const char *ssid, const char *pass, uint8_t pmk[32])
{
    size_t passLen = strlen(pass);
    if (strlen(ssid) > 32 || passLen < 8 || passLen > 63) {
        fprintf(stderr, "SSID de hasta 32 bytes y contraseña de 8 a 63 caracteres\n");
        return -1;
    }
    CCKeyDerivationPBKDF(kCCPBKDF2, pass, passLen, (const uint8_t *)ssid, strlen(ssid),
                         kCCPRFHmacAlgSHA1, 4096, pmk, 32);
    return 0;
}

// Lee "SSID\nPMK-en-hex\n". Devuelve 0 si el formato es correcto.
static int readConf(const char *path, char ssid[33], uint8_t pmk[32])
{
    FILE *f = fopen(path, "r");
    if (!f) {
        perror(path);
        return -1;
    }
    char line1[64] = {}, line2[80] = {};
    int ok = fgets(line1, sizeof(line1), f) && fgets(line2, sizeof(line2), f);
    fclose(f);
    line1[strcspn(line1, "\r\n")] = 0;
    line2[strcspn(line2, "\r\n")] = 0;
    if (!ok || strlen(line1) == 0 || strlen(line1) > 32 || strlen(line2) != 64) {
        fprintf(stderr, "%s: formato inválido\n", path);
        return -1;
    }
    strcpy(ssid, line1);
    for (int i = 0; i < 32; i++)
        if (sscanf(line2 + 2 * i, "%2hhx", &pmk[i]) != 1)
            return -1;
    memset(line2, 0, sizeof(line2));
    return 0;
}

static void setConnect(CFMutableDictionaryRef dict, const char *ssid, uint8_t pmk[32])
{
    CFStringRef s = CFStringCreateWithCString(NULL, ssid, kCFStringEncodingUTF8);
    CFDataRef k = CFDataCreate(NULL, pmk, 32);
    memset(pmk, 0, 32);
    CFDictionarySetValue(dict, CFSTR("SSID"), s);
    CFDictionarySetValue(dict, CFSTR("PMK"), k);
    CFRelease(s);
    CFRelease(k);
}

int main(int argc, char **argv)
{
    if (argc < 2 || ((!strcmp(argv[1], "connect") || !strcmp(argv[1], "pmk")) && argc != 4)) {
        fprintf(stderr, "uso: %s scan | connect <ssid> <contraseña> | disconnect |\n"
                        "       rate <n> | pmk <ssid> <contraseña> | autoconnect [archivo]\n",
                argv[0]);
        return 2;
    }

    uint8_t pmk[32];
    if (!strcmp(argv[1], "pmk")) {
        if (derivePmk(argv[2], argv[3], pmk))
            return 2;
        for (int i = 0; i < 32; i++)
            printf("%02x", pmk[i]);
        printf("\n");
        return 0;
    }

    // Al arrancar, el driver puede tardar en registrarse: esperar hasta 60 s.
    bool isAuto = !strcmp(argv[1], "autoconnect");
    io_service_t svc = 0;
    for (int i = 0; i < (isAuto ? 60 : 1) && !svc; i++) {
        svc = IOServiceGetMatchingService(kIOMainPortDefault, IOServiceMatching("RTL8723DE"));
        if (!svc && isAuto)
            sleep(1);
    }
    if (!svc) {
        fprintf(stderr, "no encontré el servicio RTL8723DE\n");
        return 1;
    }

    CFMutableDictionaryRef dict = CFDictionaryCreateMutable(NULL, 0,
        &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    CFStringRef cmd = isAuto ? CFSTR("connect")
                             : CFStringCreateWithCString(NULL, argv[1], kCFStringEncodingUTF8);
    CFDictionarySetValue(dict, CFSTR("Command"), cmd);
    if (!isAuto)
        CFRelease(cmd);

    if (!strcmp(argv[1], "rate") && argc == 3) {
        int rate = (int)strtol(argv[2], NULL, 0);
        CFNumberRef n = CFNumberCreate(NULL, kCFNumberIntType, &rate);
        CFDictionarySetValue(dict, CFSTR("Rate"), n);
        CFRelease(n);
    } else if (!strcmp(argv[1], "connect")) {
        if (derivePmk(argv[2], argv[3], pmk))
            return 2;
        setConnect(dict, argv[2], pmk);
    } else if (isAuto) {
        char ssid[33] = {};
        if (readConf(argc > 2 ? argv[2] : DEFAULT_CONF, ssid, pmk))
            return 2;
        setConnect(dict, ssid, pmk);
    }

    // El driver reintenta solo tras desconexiones; aquí se reintenta el primer
    // intento por si el AP aún no está listo (p. ej. tras un corte de luz).
    kern_return_t kr = KERN_FAILURE;
    for (int attempt = 0; attempt < (isAuto ? 5 : 1); attempt++) {
        kr = IORegistryEntrySetCFProperties(svc, dict);
        if (kr != KERN_SUCCESS)
            break;
        if (!isAuto)
            break;
        CFTypeRef stage = IORegistryEntryCreateCFProperty(svc, CFSTR("Stage"), NULL, 0);
        bool connected = stage && CFGetTypeID(stage) == CFStringGetTypeID() &&
                         CFStringCompare(stage, CFSTR("conectado"), 0) == kCFCompareEqualTo;
        if (stage)
            CFRelease(stage);
        if (connected)
            break;
        sleep(10);
    }
    CFRelease(dict);
    IOObjectRelease(svc);

    if (kr != KERN_SUCCESS) {
        fprintf(stderr, "el driver devolvió 0x%x\n", kr);
        return 1;
    }
    return 0;
}
