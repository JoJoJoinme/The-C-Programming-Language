#include <stdio.h>

#define COLUMN 40
int main(void)
{
    int c, column;
    column = 0;
    while ((c = getchar())!= EOF)
    {
        if (c == '\t')
        {
            if (column + 8 > COLUMN)
            {
                putchar('\n');
                column = 0;
            }
            else
            {
                putchar(c);
                column += 8;
            }
        }
        else
        {
            if(column >= COLUMN || c == '\n')
            {
                if (column >= COLUMN)
                    putchar('\n');
                column = 0;
            }
            else
                column += 1;
            putchar(c);
        }
    }
}