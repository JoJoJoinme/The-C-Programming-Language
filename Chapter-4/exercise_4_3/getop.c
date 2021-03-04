#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'

int getch(int queue_flag);
void ungetch(int c);

int getop(char s[], int queue_flag)
{
    int i, c;

    while ((s[0] = c = getch(queue_flag)) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch(queue_flag)))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch(queue_flag)))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}