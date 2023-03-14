#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void zero(int a)
{
    printf("zeroFun a = %d, n(a) = %x\n", a, a);
    a = 0;
    printf("zeroFun a = %d, n(a) = %x   |   ", a, a);
}

void zero2(int *b)
{
    printf("zeroFun2 b = %d, n(b) = %x\n", b, b);
    (*b) = 0;
    printf("zeroFun2 b = %d, n(b) = %x   |   ", b, b);
}


int main(void)
{
    int n = 42;       // declare an int
    int *ptrToN = &n; // set a pointer to address of n

    printf("1. n = %d\n", n);
    printf("2. (d)*ptrToN = %d\n", *ptrToN); // dereference pointer
    printf("3. (d)ptrToN = %d\n", ptrToN);
    printf("4. (x)ptrToN = %x\n", ptrToN);
    printf("5. (d)&ptrToN = %d\n", &ptrToN);
    printf("6. (x)n = %x\n", n);
    printf("7. (x)&n = %x\n", &n);
    printf("8. (x)&*ptrToN = %x\n", &*ptrToN);

    zero(n);    
    printf("Zero 1. n = %d\n", n);
    zero(ptrToN);
    printf("Zero 1.5. n = %d\n", n);
    zero2(&n);
    printf("Zero 2. n = %d\n", n);
    n = 42;
    zero2(ptrToN);
    printf("Zero 3. n = %d\n", n);
}