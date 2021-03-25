#include <stdio.h>

// void detab(int n)
void main()
{
    int c, num;
    num = 0;
    int detab;
    printf("Please input one tab equals how many spaces\n");
    scanf("%d\n",&detab);
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            num = 0;
            putchar(c);
        }
        else if (c != '\t')
        {
            num++;
            putchar(c);
        }
        else
        {
            for(int i = 0; i < (detab - num % detab); i++)
                putchar(' ');
            num = 0;
        }
    }
    
}