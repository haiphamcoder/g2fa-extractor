#include "base64.h"
#include <string.h>
#include <ctype.h>

static const char BASE64_TABLE[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

size_t base64_decode(const char *input, uint8_t *output) {
    size_t input_length = 0;
    size_t output_length = 0;
    int buffer = 0, bits_collected = 0;

    while (*input) {
        char ch = *input++;
        if (isspace(ch) || ch == '=') {
            continue;
        }

        const char *ptr = strchr(BASE64_TABLE, ch);
        if (!ptr) {
            return 0;  // Invalid character in input
        }

        buffer = (buffer << 6) | (ptr - BASE64_TABLE);
        bits_collected += 6;
        if (bits_collected >= 8) {
            bits_collected -= 8;
            output[output_length++] = (uint8_t)(buffer >> bits_collected);
            buffer &= (1 << bits_collected) - 1;
        }
    }

    return output_length;
}
