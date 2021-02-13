#include<stdio.h>

unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0<<n)<<(p+1-n));
}

void main()
{
    unsigned int x;
    x = 0x12345678;
    printf("input was 0x:%08X\n", x);
    printf("after invert got: 0x:%08X\n", invert(x,5,4));
}
