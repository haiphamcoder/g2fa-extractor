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

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)
