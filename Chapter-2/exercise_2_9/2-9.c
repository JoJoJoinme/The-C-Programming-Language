#include <stdio.h>
#include <math.h>


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


int bitcount(int x)
{
    int b = 0;
    while(x)
    {
        x &= (x - 1);
        ++b;
    }

    return b;
}

int main(void)
{
    unsigned int x = 0x011010;
    printbin(x);
    printf("\nBitcount of input get:%d",bitcount(x));

    return 0;
}

