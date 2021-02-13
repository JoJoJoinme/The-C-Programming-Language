#include<stdio.h>
#include<stdlib.h>


int bitcount(int x)
{
    int temp=1;
    if(x==0)
	return 0;
    while(x&=(x-1))
        temp++;
    return temp;
}

void main(int argc, char *argv[])
{
    int arg;
    arg = 3;
    printf("\nBitcount of input get:%d",bitcount(arg));

}

