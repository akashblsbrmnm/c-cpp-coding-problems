#include <stdio.h>

#define SET_BIT(REG, POS) (REG|=(1U<<POS))
#define CLEAR_BIT(REG, POS) (REG&=~(1U<<POS))
#define TOGGLE_BIT(REG, POS) (REG^=(1U<<POS))
#define IS_SET_BIT(REG, POS) (REG & (1 << POS))
#define IS_ODD(REG) (REG & 1U)

/* Problem: Count the set bits in a number using Bit Manipulation */
int count_bits(int reg_num)
{
    int count = 0;
    while(reg_num)
    {
        reg_num &= (reg_num - 1);
        count++;
    }
    return count;
}

/* Problem: Given an array of size N-1 containing numbers from 1 to N with one number missing, find the missing number without using extra space. */
int find_missing(int arr[], int n)
{
    int xor1 = 0, xor2 = 0;
    for(int i = 1; i<=n; i++)
        xor1 ^= i;
    for(int i = 0; i < n-1; i++)
        xor2 ^= arr[i];

    return xor1 ^ xor2;
}

/* Problem: Find if the number is power of two */
int is_power_of_two(unsigned int n)
{
    if(n == 0) return -1;
    return (n & (n - 1)) == 0;
}

int main() {

}
