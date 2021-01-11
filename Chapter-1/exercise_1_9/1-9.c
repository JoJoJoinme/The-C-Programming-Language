#include<stdio.h>

void main()
{
    int last, c;
    last = -1;
    while((c = getchar()) != EOF)
    {
       if(c == ' ' && (last == c))
           continue;
       last = c;
       putchar(last);
    }
}
