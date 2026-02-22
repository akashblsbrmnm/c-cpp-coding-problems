#include <stdio.h>
#include <stdint.h>


int reverse_of_number(int num)
{
    int rev = 0;
    while(num!=0)
    {
        rev = (rev*10) +  num % 10;
        num = num/10;
    }
    return rev;
}

int sum_of_digits(int num)
{
    int sum = 0;
    while(num!=0)
    {
        sum = sum + (num % 10);
        num/=10;
    }
    return sum;
}

int print_numbers_recursion()
{
    static int n = 1;
    if(n>100)
        return 0;
    
    printf("%d\t", n++);
    print_numbers_recursion();
}

int main()
{
    uint32_t num = 0x12345678;
    unsigned char* bytes =  (unsigned char*) &num;
    
    if(bytes[0] == 0x12)
        printf("Big Endian\n");
    else
        printf("Little Endian\n");
    int res = reverse_of_number(657);
    printf("%d\n", res);
    // print_numbers_recursion();
    printf("%d\n", sum_of_digits(75));
    return 0;
}
