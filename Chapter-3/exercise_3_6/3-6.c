#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

void reverse(char s[])
{
    int i, j, c;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

void itoa(int n, char s[], int width)
{
    int sign, i;
    unsigned c;
    if ((sign = n) < 0)
        c = -n;
    i = 0;
    do
    {
        s[i++] = (c % 10) + '0';
    } while ((c /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    while(width > 0)
    {
        s[i++] = ' ';
        width--;
    }
    s[i] = '\0';
    reverse(s);
}

int main()
{
    int n, width;
    char s[MAXSIZE];
    n = 1 << 31;
    width = 5;
    itoa(n, s, width);
    printf("itoa(%d) return:\n %s", n, s);
}
