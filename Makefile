CC = gcc
CFLAGS = -Wall -Iinclude -I/usr/include/protobuf-c
LDFLAGS = -lprotobuf-c
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

PROTO_SRC = $(SRC_DIR)/otpauth_migration.pb-c.c
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/base32.c $(SRC_DIR)/base64.c $(SRC_DIR)/urldecode.c $(PROTO_SRC)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
TARGET = $(BIN_DIR)/g2fa-extractor

.PHONY: all clean prepare

all: prepare $(TARGET)

prepare:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
	@echo "Build completed: $(TARGET)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "Cleaned build and bin directories."
