#include<stdio.h>

void main()
{
    int space, table, newline, other, c;
    c = 0;
    space = 0;
    table = 0;
    newline = 0;
    while((c = getchar()) != EOF)
    {
       if(c == '\n')
           ++newline;
       else if(c == ' ')
	   ++space;
       else if(c == '\t')
	   ++table;
       else
	   ++other;
    }
    printf("space num is:%d\ntable num is:%d\nnewline num is:%d\nother character num is:%d", space, table, newline, other);
}
