# DX-BT36 Firmware Makefile
# For Dialog DA14535 SDK

# 工具链
PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc
OBJCOPY = $(PREFIX)objcopy
OBJDUMP = $(PREFIX)objdump
SIZE = $(PREFIX)size

# SDK 路径
SDK_DIR = ../SDK/DA14535_SDK
BUILD_DIR = build

# 源文件
USER_SRCS = user_app/main.c \
            user_app/user_ble_service.c \
            user_app/user_adv.c \
            user_app/user_uart.c \
            custom_profile.c

# 头文件路径
USER_INC = -Iuser_app \
           -I$(SDK_DIR)/include \
           -I$(SDK_DIR)/sdk/modules/system/include

# 编译选项
CFLAGS = -mcpu=cortex-m0 -mthumb -Wall -fdata-sections -ffunction-sections
CFLAGS += -O2 -g3
CFLAGS += $(USER_INC)

# 链接选项
LDFLAGS = -mcpu=cortex-m0 -mthumb -specs=nano.specs -specs=nosys.specs
LDFLAGS += -L$(SDK_DIR)/libs -lBLEStack
LDFLAGS += -Wl,--gc-sections -Wl,-Map=$(BUILD_DIR)/firmware.map

# 目标
TARGET = $(BUILD_DIR)/firmware

.PHONY: all clean

all: $(BUILD_DIR) $(TARGET).hex $(TARGET).bin

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# 编译目标文件
$(BUILD_DIR)/%.o: user_app/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 链接
$(TARGET).elf: $(BUILD_DIR)/*.o
	$(CC) $(LDFLAGS) $^ -o $@

# 生成 HEX
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

# 生成 BIN
$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

# 显示大小
size: $(TARGET).elf
	$(SIZE) $<

clean:
	rm -rf $(BUILD_DIR)

# 显示帮助
help:
	@echo "DX-BT36 Firmware Build System"
	@echo ""
	@echo "Targets:"
	@echo "  all      - Build firmware (default)"
	@echo "  clean    - Clean build files"
	@echo "  size     - Show firmware size"
	@echo ""
	@echo "Outputs:"
	@echo "  build/firmware.hex - Intel HEX format"
	@echo "  build/firmware.bin - Binary format"
