#include <stdio.h>

void print_binary(int x) {
    for(int i = 7; i >= 0; i--) {
        printf("%d ", (x >> i)&1u);
    }
}

int set_bit(int num, int pos) {
    return num | (1u << pos);
}

int clear_bit(int num, int pos) {
    return num & ~(1u << pos);
}

int toggle_bit(int num, int pos) {
    return num ^ (1u << pos);
}

int count_bits(int num) {
    int count = 0;
    while(num > 0) {
        num &= (num-1);
        count++;
    }
    return count;
}

int is_num_power_of_two(int n) {
    return n && !(n & (n - 1));
}

int swap(int *a, int* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main() {
	int num = 12;
    print_binary(num);
    int set = set_bit(num, 0);
    if(set == 13) printf("YES\n");
    else printf("NO\n");
    print_binary(set);
    
    int clear = clear_bit(set, 0);
    if(clear == num) {
        printf("WORKED\n");
    }
    else {
        printf("NOT WORKED\n");
    }
    
    int tog = toggle_bit(num, 2);
    if(tog == 8) {
        printf("toggle_bit works\n");
    }
    else {
        printf("toggle_bit not working\n");
    }
    int count = count_bits(14);
    printf("The no. of set bits in %d: %d ( ", 14, count);
    print_binary(14);
    printf(")");
    
    printf("\n%d to power of 2 is: %d\n", 3, is_num_power_of_two(3));
    int a =10, b = 80;
    swap(&a,&b);
    printf("After swaping: a = %d, b = %d\n", a, b);
    return 0;
}
