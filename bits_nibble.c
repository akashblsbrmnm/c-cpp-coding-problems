#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t num = 0xAB;
    uint8_t high = (num & 0xF0) >> 4;
    uint8_t low  = num & 0x0F;
    printf("High nibble: 0x%X, Low nibble: 0x%X\n", high, low);
	uint8_t swapped = (low << 4) | high;
    return 0;
}
