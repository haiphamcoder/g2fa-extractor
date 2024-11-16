#include "base32.h"
#include <stdlib.h>
#include <string.h>

static const char BASE32_ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";

char *base32_encode(const uint8_t *data, size_t length) {
    size_t output_length = (length * 8 + 4) / 5;
    char *encoded = (char *)malloc(output_length + 1);
    if (!encoded) {
        return NULL;
    }

    size_t index = 0, bit_buffer = 0, bits_left = 0;
    for (size_t i = 0; i < length; i++) {
        bit_buffer = (bit_buffer << 8) | data[i];
        bits_left += 8;

        while (bits_left >= 5) {
            encoded[index++] = BASE32_ALPHABET[(bit_buffer >> (bits_left - 5)) & 0x1F];
            bits_left -= 5;
        }
    }

    if (bits_left > 0) {
        encoded[index++] = BASE32_ALPHABET[(bit_buffer << (5 - bits_left)) & 0x1F];
    }

    encoded[index] = '\0';
    return encoded;
}
