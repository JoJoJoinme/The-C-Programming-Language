#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int getch(void);
void ungetch(int);


int getfloat(double *pn)
{
    int c, i, sign;

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
    i = 0;
    for (*pn = 0; isdigit(c); c = getch())
        *pn = *pn * 10 + (c - '0');
    if (c == '.')
        for (i = 0; isdigit(c = getch()); i++)
            *pn = *pn * 10 + (c - '0');
    while (i--)
        *pn = *pn / 10;
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}


int main()
{
    int n, getfloat(double *);
    double arr[SIZE];
    for (n = 0; n < SIZE && getfloat(&arr[n]) != EOF; n++)
        ;
    for (n = 0; n < SIZE; n++)
        printf("%f\t", arr[n]);
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
