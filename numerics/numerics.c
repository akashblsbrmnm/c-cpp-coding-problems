#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int factorial_it(int n)
{
    int fact = 1;
    for(int i = 1; i<=n; i++) fact *= i;
    return fact;
}

bool isPalindrome_s(char *str) {
    char* start = str;
    char* end = str + strlen(str) - 1;

    while(start < end) {
        if(*start != *end) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool isPalindrome_n(int num) {
    int rev = 0;
    int copy = num;
    while(num) {
        rev = rev * 10 + (num % 10);
        num = num / 10;
    }
    if(rev == copy) return true;
    else return false;
}

int sumOfDigits(int num) {
    int sum = 0;
    while(num) {
        sum = sum + (num % 10);
        num /= 10;
    }
    return sum;
}

int factorial(int n) {
    if(n <= 1)
        return 1;
    return n* factorial(n - 1);
}

bool isStrong(int num) {
    int sum = 0;
    int copy  = num;
    while(num) {
        sum = sum + factorial(num % 10);
        num /= 10;
    }
    if(sum == copy) return true;
    return false;
}

bool isPrime(int num) {
    if(num < 2) return false;
    if(num == 2) return true;
    if(num %2 == 0) return false;
    for(int i = 3; i <= num / i; i+=2) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int fibonacci(int n) {
    if(n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int x = 787;
    printf("x: %d\n", x);
    if(isPalindrome_n(x)) {
        printf("Number is palindrome\n");
    } else {
        printf("Number is not palindrome\n");
    }
    char str[] = "apple";
    if (isPalindrome_s(str)) {
        printf("String is palindrome\n");
    } else {
        printf("String is not palindrome\n");
    }
    printf("Sum of digits: %d\n", sumOfDigits(x));
    printf("Is 40585 a strong number ? %s\n" , isStrong(40585) ? "YES" : "NO");
    printf("Is x prime ? %s\n", isPrime(x) ? "YES" : "NO");
    for(int i=0; i< x/40; i++) {
        printf("%d, ", fibonacci(i));
    }
    return 0;
    
}