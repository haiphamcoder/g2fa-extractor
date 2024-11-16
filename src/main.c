#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <protobuf-c/protobuf-c.h>
#include "otpauth_migration.pb-c.h"
#include "base64.h"
#include "urldecode.h"
#include "base32.h"

#define PREFIX "otpauth-migration://offline?data="

void decode_payload(const uint8_t *data, size_t length) {
    Payload *payload = payload__unpack(NULL, length, data);
    if (payload == NULL) {
        fprintf(stderr, "Error unpacking protobuf data.\n");
        return;
    }

    for (size_t i = 0; i < payload->n_otp_parameters; i++) {
        Payload__OtpParameters *otp = payload->otp_parameters[i];
        printf("Issuer: %s\n", otp->issuer);
        printf("Name: %s\n", otp->name);

        // Mã hóa secret key sang base32
        char *secret_key = base32_encode(otp->secret.data, otp->secret.len);
        if (secret_key) {
            printf("Secret Key: %s\n", secret_key);
            free(secret_key);
        } else {
            printf("Failed to encode secret key.\n");
        }
    }

    payload__unpack(NULL,length, payload);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <otpauth-migration URL>\n", argv[0]);
        return 1;
    }

    if (strncmp(argv[1], PREFIX, strlen(PREFIX)) != 0) {
        fprintf(stderr, "Invalid input format. Expected prefix: %s\n", PREFIX);
        return 1;
    }

    const char *encoded_data = argv[1] + strlen(PREFIX);

    char decoded_url[2048];
    urldecode(decoded_url, encoded_data);

    uint8_t decoded_data[1024];
    size_t decoded_size = base64_decode(decoded_url, decoded_data);

    if (decoded_size == 0) {
        fprintf(stderr, "Error decoding base64 data.\n");
        return 1;
    }

    decode_payload(decoded_data, decoded_size);

    return 0;
}
