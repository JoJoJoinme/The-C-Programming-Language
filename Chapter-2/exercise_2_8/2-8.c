#include<stdio.h>

unsigned rightrot(unsigned x, int n)
{
    return (x&(~(~0<<n)))<<(32-n)|(x>>n);
}

void main()
{
    unsigned x, m;
    x = 0x12345678;
    printf("input: 0x:%08x\n",x);
    m = rightrot(x, 5);
    printf("after changed: 0x:%08x\n", m);

}
