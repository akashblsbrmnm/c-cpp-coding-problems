#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SET_BIT(PORT, BIT)    ( (PORT) |= (1U << (BIT)) )
#define CLEAR_BIT(PORT, BIT)  ( (PORT) &= ~(1U << (BIT)) )
#define TOGGLE_BIT(PORT, BIT) ( (PORT) ^= (1U << (BIT)) )
#define IS_BIT_SET(PORT, BIT)  ( ((PORT) >> (BIT)) & 1U )

void print_bin(uint8_t n)
{
    for (int i = 7; i >= 0; i--)
        printf("%d", (n >> i) & 1);
    printf("\n");
}

void isEvenOrOdd(uint8_t num)
{
	if (num & 1)
		printf("%d is Odd\n", num);
	else
		printf("%d is Even\n", num);
}

uint8_t setBit(uint8_t num, int k)
{
	return num | (1 << k);
}

uint8_t clearBit(uint8_t num, int k)
{
	return num & ~(1 << k);
}

uint8_t toggleBit(uint8_t num, int k)
{
	return num ^ (1 << k);
}

bool isBitSet(uint32_t num, int k)
{
	return ((num >> k) & 1) ? true : false;
}

int countBits(uint8_t n)
{
	int count = 0;
	while (n != 0)
	{
		n &= (n - 1);
		count++;
	}
	return count;
}

void isPowerofTwo(uint8_t n)
{
	if (n > 0 && (n & (n - 1)) == 0)
		printf("%d is Power of 2\n", n);
	else
		printf("%d is NOT Power of 2\n", n);
}

int findSingle(int arr[], int n)
{
	int single = 0;
	for (int i = 0; i < n; i++)
		single ^= arr[i];
	return single;
}

int main()
{
	uint8_t n = 5;

	printf("n in binary: ");
	print_bin(n);

	// Even or odd
	isEvenOrOdd(n);

	// Set bit 1
	uint8_t s = setBit(n, 1);
	printf("After setting bit 1: ");
	print_bin(s);

	// Clear bit 2
	uint8_t c = clearBit(n, 2);
	printf("After clearing bit 2: ");
	print_bin(c);

	// Toggle bit 0
	uint8_t t = toggleBit(n, 0);
	printf("After toggling bit 0: ");
	print_bin(t);

	// Is bit 2 set?
	printf("Is bit 2 set in %d? %s\n", n, isBitSet(n, 2) ? "Yes" : "No");

	// Count number of 1s
	printf("Number of set bits in %d = %d\n", n, countBits(n));

	// Check power of 2
	isPowerofTwo(n);
	isPowerofTwo(8); // another test

	// findSingle example
	int arr[] = {4, 2, 4, 5, 2};
	int unique = findSingle(arr, 5);
	printf("Single element in array = %d\n", unique);

	return 0;
}
