#include<stdio.h>

unsigned setbits(unsigned x, int p, int n, int y)
{
    unsigned right;
    x = x & ~(~(~0<<n)<<(p+1-n));
    if(!y)
        return x;
    return x ^ (~(~0<<n)<<(p+1-n));



}

void main()
{
    unsigned int x;
    x = 0xffffffff;
    printf("Input 0x:%08X\n", x);
    x = setbits(x, 5,4,0);
    printf("After setbits: 0x:%08X\n",x);

}
