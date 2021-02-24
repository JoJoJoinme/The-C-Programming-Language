#include <stdio.h>
#include <math.h>

void printbin(unsigned int x);
unsigned int rightrot(unsigned int x, unsigned int n);


void main()
{
//    unsigned x, m;
    //x = 0x12345678;
    //printf("input: 0x:%08x\n",x);
    //m = rightrot(x, 5);
    //printf("after changed: 0x:%08x\n", m);

    unsigned int x = 0b11110101;

    printbin(x);
    printbin(rightrot(x, 5));



}

void printbin(unsigned int x)
{
    unsigned int n = sizeof(unsigned int);
    
    printf("0b");

    int i;
    for(i = n * 8 - 1; i >= 0; --i)
    {
        (x & (unsigned int)pow(2, i)) ? putchar('1') : putchar('0');
    }

    putchar('\n');
}


unsigned rightrot(unsigned x, unsigned n)
{
    return (x&(~(~0<<n)))<<(32-n)|(x>>n);
}
