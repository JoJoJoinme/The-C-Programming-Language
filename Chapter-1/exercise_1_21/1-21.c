#include <stdio.h>

#define TAB 8

int main(void)
{
    int c, num, space_num;
    num = 0;
    space_num = 0;
    while ((c = getchar()) != EOF)
    {
        num++;
        if (c == ' ')
            if (num % 8 == 0)
                space_num = 0, putchar('\t');
            else
                space_num++;
        else
            if (c != '\t' && c != '\n')
                for (int i = 0; i < space_num; i++)
                    putchar(' ');
            space_num = 0;
            putchar(c);
    }
    
}