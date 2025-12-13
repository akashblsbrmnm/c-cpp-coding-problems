#include <stdio.h>
#include <stdbool.h>

int factorial(int n)
{
    int fact = 0;
    for(int i = 1; i<=n; i++) fact *= i;
    return fact;
}

int factorail_rec(int n)
{
    if(n <= 1) return 1;
    return n * factorail_rec(n -1);
}

bool is_prime(int n)
{
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    
    for(int i =3; i * i <= n; i+=2)
    {
        if(n % i ==0) return false;
    }
    return true;
}


int main()
{

}