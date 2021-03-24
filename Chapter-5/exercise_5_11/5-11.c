#include <stdio.h>
#include <stdlib.h>

void detab(int tab);
void entab(int tab);


int main(int argc, char *argv[])
{
    int tab;
    if (argc == 1)
        tab = 8;
    else if (argc == 2)
        tab = atoi(*(++argv));
    else
        printf("Too many arguments, Expect 0 or 1 argument");
    printf("TAB equals %d Spaces\n", tab);
    printf("Below is detab function\n")
    detab(tab);
    printf("Below is entab function\n")   
    entab(tab);
    
}

void detab(int tab)
{
    int c, num;
    num = 0;
    int detab;
    detab = tab;
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

void entab(int tab)
{
    int c, num, space_num;
    num = 0;
    space_num = 0;
    while ((c = getchar()) != EOF)
    {
        num++;
        if (c == ' ')
            if (num % tab == 0)
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