#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Function to compute CRC-12
uint16_t compute_crc12(const uint8_t *data, size_t length) {
    uint16_t crc = 0xFFF;  // Initial CRC value for CRC-12
    const uint16_t polynomial = 0x80F;  // Polynomial for CRC-12

    // Process each byte of data
    for (size_t i = 0; i < length; i++) {
        crc ^= (data[i] << 4);  // XOR the data byte into the CRC value
        for (int j = 0; j < 8; j++) {
            if (crc & 0x800) {
                crc = (crc << 1) ^ polynomial;  // If the MSB is set, XOR with the polynomial
            } else {
                crc <<= 1;  // Otherwise just shift the CRC value
            }
        }
    }

    return crc & 0xFFF;  // Mask to 12 bits to keep CRC-12
}

// Function to compute CRC-16
uint16_t compute_crc16(const uint8_t *data, size_t length) {
    uint16_t crc = 0xFFFF;  // Initial CRC value for CRC-16
    const uint16_t polynomial = 0x8005;  // Polynomial for CRC-16

    // Process each byte of data
    for (size_t i = 0; i < length; i++) {
        crc ^= (data[i] << 8);  // XOR the data byte into the CRC value
        for (int j = 0; j < 8; j++) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ polynomial;  // If the MSB is set, XOR with the polynomial
            } else {
                crc <<= 1;  // Otherwise just shift the CRC value
            }
        }
    }

    return crc & 0xFFFF;  // Mask to 16 bits to keep CRC-16
}

// Function to compute CRC-CCITT
uint16_t compute_crc_ccitt(const uint8_t *data, size_t length) {
    uint16_t crc = 0xFFFF;  // Initial CRC value for CRC-CCITT
    const uint16_t polynomial = 0x1021;  // Polynomial for CRC-CCITT

    // Process each byte of data
    for (size_t i = 0; i < length; i++) {
        crc ^= (data[i] << 8);  // XOR the data byte into the CRC value
        for (int j = 0; j < 8; j++) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ polynomial;  // If the MSB is set, XOR with the polynomial
            } else {
                crc <<= 1;  // Otherwise just shift the CRC value
            }
        }
    }

    return crc & 0xFFFF;  // Mask to 16 bits to keep CRC-CCITT
}

int main() {
    uint8_t data[] = "Hello, CRC!";  // Input data to calculate CRC on
    size_t length = strlen((char *)data);  // Get the length of the data

    printf("Data: %s\n", data);  // Print the input data
    printf("CRC-12: %03X\n", compute_crc12(data, length));  // Print CRC-12 in hexadecimal format
    printf("CRC-16: %04X\n", compute_crc16(data, length));  // Print CRC-16 in hexadecimal format
    printf("CRC-CCITT: %04X\n", compute_crc_ccitt(data, length));  // Print CRC-CCITT in hexadecimal format

    return 0;
}

/*Data: Hello, CRC!
CRC-12: 0BA
CRC-16: B612
CRC-CCITT: CC97*/
