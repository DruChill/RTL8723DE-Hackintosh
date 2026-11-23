# Compila el kext en el Mac (x86_64, destino macOS 15) para la HP.
NAME   := RTL8723DE
SDK    := $(shell xcrun --sdk macosx --show-sdk-path)
KHDR   := $(SDK)/System/Library/Frameworks/Kernel.framework/Headers
BUILD  := build
KEXT   := $(BUILD)/$(NAME).kext

CXXFLAGS := -arch x86_64 -mmacosx-version-min=15.0 -std=gnu++17 -O2 \
  -mkernel -fapple-kext -fno-rtti -fno-exceptions -fno-builtin -fno-common \
  -nostdinc -nostdlibinc -isysroot $(SDK) -I$(KHDR) -I$(KHDR)/libkern/c++ \
  -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE -DAPPLE -DNeXT -Wall \
  -Wno-deprecated-declarations

CFLAGS := -arch x86_64 -mmacosx-version-min=15.0 -O2 -mkernel -fno-builtin \
  -fno-common -nostdinc -isysroot $(SDK) -I$(KHDR) -DKERNEL -Wall

CXX_SRCS := src/RTL8723DE.cpp src/Station.cpp src/NetIf.cpp
C_SRCS   := src/kmod_info.c src/wpa_crypto.c
OBJS     := $(CXX_SRCS:src/%.cpp=$(BUILD)/%.o) $(C_SRCS:src/%.c=$(BUILD)/%.o)

all: $(KEXT) $(BUILD)/rtlctl

$(BUILD)/%.o: src/%.cpp src/*.h src/*.hpp
	mkdir -p $(BUILD)
	xcrun clang++ $(CXXFLAGS) -c $< -o $@

$(BUILD)/%.o: src/%.c src/*.h
	mkdir -p $(BUILD)
	xcrun clang $(CFLAGS) -c $< -o $@

$(KEXT): $(OBJS) Info.plist
	mkdir -p $(KEXT)/Contents/MacOS
	xcrun clang++ -arch x86_64 -mmacosx-version-min=15.0 -isysroot $(SDK) \
	  -nostdlib -Xlinker -kext -Xlinker -no_data_const \
	  $(OBJS) -L$(SDK)/usr/lib -lkmodc++ -lkmod \
	  -o $(KEXT)/Contents/MacOS/$(NAME)
	cp Info.plist $(KEXT)/Contents/Info.plist
	codesign -s - --force $(KEXT)

$(BUILD)/rtlctl: tools/rtlctl.c
	mkdir -p $(BUILD)
	xcrun clang -arch x86_64 -mmacosx-version-min=15.0 -O2 -Wall \
	  -framework IOKit -framework CoreFoundation tools/rtlctl.c -o $@
	codesign -s - --force $@

# Pruebas de la criptografía WPA2 en el Mac contra vectores oficiales.
test: tools/test_crypto.c src/wpa_crypto.c src/wpa_crypto.h
	mkdir -p $(BUILD)
	xcrun clang -O2 -Wall tools/test_crypto.c src/wpa_crypto.c -o $(BUILD)/test_crypto
	$(BUILD)/test_crypto

clean:
	rm -rf $(BUILD)

.PHONY: all test clean
