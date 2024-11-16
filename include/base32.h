#ifndef BASE32_H
#define BASE32_H

#include <stddef.h>
#include <stdint.h>

char *base32_encode(const uint8_t *data, size_t length);

#endif
