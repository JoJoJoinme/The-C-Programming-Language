/* htoi(s) */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 1000

int htoi(char s[]);

int getHexString(char line[], int limit, char dest[]);

int main()
{
    unsigned int len, hexToDecimalRes;
    char string[MAXSIZE], stripped[MAXSIZE];
    printf("Please input a string :\n");
    while ((len = getHexString(string, MAXSIZE, stripped)) > 0)
    {
        printf("stripped string got: %s\n", stripped);
        hexToDecimalRes = htoi(stripped);
    }
    printf("HexToDecimal result is %u\n", hexToDecimalRes);
}

int htoi(char src[])
{
    unsigned int sum, cur;
    sum = cur = 0;
    while (*src != '\n')
    {
        if ((*src >= 97) && (*src <= 103))
        {
            cur = *src - 87;
        }
        else
        {
            cur = *src - '0';
        }
        //printf("current char: %c decimai is: %d\n", *src, cur);
        sum = sum * 16 + cur;
        src++;
    }
    return sum;
}

int getHexString(char s[], int lim, char dest[])
{
    int i;
    char c;
    bool flag;
    flag = false;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if (c >= 65 && c <= 90)
            c += 32;
        if ((c >= 48 && c <= 57) || (c >= 97 && c <= 103) || (!flag && c == 'x'))
        {
            if (c == 'x')
                flag = true;
            s[i] = c;
            continue;
        }
        printf("Wrong Input of char: %c\n", c);
        abort();
    }
    if (c == '\n')
    {
        s[i++] = '\n';
    }
    s[i] = '\0';
    //   printf("input string is:%s", s);
    if (i >= 2)
    {
        if (*s == '0' && ((c = *(++s)) == 'x'))
        {
            ++s;
        }
    }
    i = 0;
    while (*s && ((*s) != '\n'))
    {
        dest[i++] = *s++;
    }
    dest[i] = '\n';
    return i;
}
