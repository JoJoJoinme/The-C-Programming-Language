#include <stdio.h>
#include <string.h>


int printd(int n, char s[], int i)
{
    s[i] = n % 10 + '0';
    if (n > 0)
        return printd(n/10, s, ++i);
    return i;
}

void reverse(char s[])
{
    int i, j, c;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}


void itoa(int n, char s[])
{
    int sign = 0, last = 0;
    if (n < 0)
    {
       n = -n;
       sign = 1;
    }
    last = printd(n, s, 0);
    if (sign == 1)
        s[last++] = '-';
    s[last] = '\0';
    reverse(s);
}

void main()
{
    int n = 54321;
    char s[20];
    itoa(n, s);
    printf("itoa(%d) -->%s\n", n, s);
    n = -54321;
    itoa(n, s);
    printf("itoa(%d) -->%s\n", n, s);
}