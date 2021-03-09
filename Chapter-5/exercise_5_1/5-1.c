#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int getch(void);
void ungetch(int);


int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        if (!isdigit(c = getch()))
        {
            ungetch(c);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = *pn * 10 + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}


int main()
{
    int n, arr[SIZE], getint(int *);
    for (n = 0; n < SIZE && getint(&arr[n]) != EOF; n++)
        ;
}


#define BUFFSIZE 100

int bufp = 0;
char buf[BUFFSIZE];

int getch(void)
{
    return bufp > 0 ? buf[--bufp]: getchar();
}

void ungetch(int c)
{
    bufp < BUFFSIZE ? buf[bufp++] = c : printf("The Stack is full!\n");
}
