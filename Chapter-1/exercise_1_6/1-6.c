#include<stdio.h>

void main()
{
    int c;
    c = 0;
    printf("The getchar() return: %d\n", (getchar() != EOF)? 1:0);
}
