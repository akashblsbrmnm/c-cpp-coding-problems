#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef unsigned int uint;

#define SET_BIT(REG, POS) (REG|=(1U<<POS))
#define CLEAR_BIT(REG, POS) (REG&=~(1U<<POS))
#define TOGGLE_BIT(REG, POS) (REG^=(1U<<POS))
#define IS_SET_BIT(REG, POS) (REG & (1U << POS))
#define IS_ODD(REG) (REG & 1U != 0)

/* Print the binary representation */
void print_bin(unsigned int a) {
    for(int i = 7; i >= 0; i--) {
        printf("%d", (a >> i) & 1);
    }
}

/* Problem: Count the set bits in a number using Bit Manipulation */
int count_set_bits(uint num)
{
    int count = 0;
    while(num != 0) {
        num = num & (num - 1);  // Removes the lowest set bit
        count++;
    }
    return count;
}

/* Problem: Given an array of size N-1 containing numbers from 1 to N with one number missing, find the missing number without using extra space. */
int find_missing(int arr[], int n)
{
    int xor1 = 0, xor2 = 0;
    for(int i = 1; i <= n; i++)
        xor1 ^= i;
    for(int i = 0; i < n - 1; i++)
        xor2 ^= arr[i];

    return xor1 ^ xor2;
}

uint set_bit(uint reg, int pos) {
    return reg | (1u << pos);
}

uint clear_bit(uint reg, int pos) {
    return reg & ~(1u << pos);
}

uint toggle_bit(uint reg, int pos) {
    return reg ^ (1u << pos);
}

bool is_set_bit(uint reg, int pos) {
    return (reg & (1u << pos)) != 0;
}

/*
 * Counts the number of bit positions that differ between two unsigned integers (Hamming Distance).
 */
unsigned int count_bits_to_flip(unsigned int a, unsigned int b)
{
    unsigned int xor_result = a ^ b;
    unsigned int count = 0;

    while (xor_result != 0)
    {
        xor_result &= (xor_result - 1);  // Remove lowest set bit
        count++;
    }

    return count;
}

/* Prime number check using bit manipulation */
bool is_prime(uint num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (uint i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}

/* Check if a number is a power of 2 */
bool is_power_of_two(uint num) {
    return num != 0 && (num & (num - 1) == 0);
}

/* Swap nibbles in a byte */
uint32_t swap_nibble(uint32_t num) {
    uint32_t high = (num & 0xF0) >> 4;
    uint32_t low = (num & 0x0F);
    return (low << 4) | high;
}

/* Swap two numbers without using temporary variable */
void swap(uint32_t *a, uint32_t *b) {
    if (a == b) return;
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

/* Check endianness of the system */
void endian_check(uint num) {
    unsigned char* c = (unsigned char*) &num;
    if (c[0] == 1) {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }
}

/* Driver code for testing */
int main() {
    // Test Set, Clear, Toggle, and Check Bit Functions
    uint reg = 0x10;  // 0001 0000 in binary
    printf("Initial reg: 0x%X\n", reg);
    
    reg = SET_BIT(reg, 2);    // Set 2nd bit: 0001 0100
    printf("After SET_BIT(2): 0x%X\n", reg);
    
    reg = CLEAR_BIT(reg, 4);  // Clear 4th bit: 0000 0100
    printf("After CLEAR_BIT(4): 0x%X\n", reg);
    
    reg = TOGGLE_BIT(reg, 1); // Toggle 1st bit: 0000 0000
    printf("After TOGGLE_BIT(1): 0x%X\n", reg);
    
    bool isSet = IS_SET_BIT(reg, 0); // Check if 0th bit is set
    printf("Is 0th bit set? %s\n", isSet ? "Yes" : "No");
    
    printf("Is %u odd? %s\n", reg, IS_ODD(reg) ? "Yes" : "No");

    // Test count_set_bits
    uint num = 29;  // 11101 in binary
    printf("Set bits in %u: %d\n", num, count_set_bits(num));

    // Test find_missing
    int arr[] = {1, 2, 4, 5, 6};
    int n = 6;
    printf("Missing number is: %d\n", find_missing(arr, n));

    // Test Hamming Distance
    unsigned int a = 10, b = 12;
    printf("Hamming distance between %u and %u: %u\n", a, b, count_bits_to_flip(a, b));

    // Test is_prime
    uint prime_test = 19;
    printf("Is %u prime? %s\n", prime_test, is_prime(prime_test) ? "Yes" : "No");

    // Test is_power_of_two
    uint power_test = 16;
    printf("Is %u a power of two? %s\n", power_test, is_power_of_two(power_test) ? "Yes" : "No");

    // Test swap_nibble
    uint32_t num_to_swap = 0xAB;  // 10101011 in binary
    printf("After swapping nibbles: 0x%X\n", swap_nibble(num_to_swap));

    // Test swap without temp
    uint32_t x = 5, y = 10;
    printf("Before swap: x = %u, y = %u\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %u, y = %u\n", x, y);

    // Test Endianess
    uint num_check = 1;
    endian_check(num_check);

    return 0;
}

