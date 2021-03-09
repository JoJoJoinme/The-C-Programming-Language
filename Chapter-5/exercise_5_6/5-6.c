#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXSIZE 1000

int getlineV1(char *s, int lim)
{
    int i, c;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        *s++ = c;
    if (c == '\n')
    {
        *s++ = '\n';
        ++i;
    }
    *s = '\0';
    return i;
}

int getlineV2(char *s, int lim)
{
    int c, i;
    char *p;
    p = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = '\n';
    *s = '\0';
    return s - p;
}

int atoi(char *s)
{
    int n = 0, sign;

    sign = (*s == '-') ? -1 : 1;
    if (*s == '-' || *s == '+')
        s++;
    for (n = 0; isdigit(*s); s++)
        n = n * 10 + (*s - '0');
    return n * sign;
}

/* recursion reverse */
void reverse(char *s)
{
    int len;
    len = strlen(s);
    if (len > 1)
    {
        int temp;
        temp = *s;
        *s = *(s + len - 1);
        if (len == 2)
            *(s + len - 1) = temp;
        else
        {
            *(s + len - 1) = '\0';
            reverse(s+1);
            *(s + len - 1) = temp;
        }
    }
}

/* reverseV2 -> normal reverse */
void reverseV2(char *s)
{
    char *t;

    t = s;
    while (*t)
        t++;

    while (t >= s + 2)
    {
        int c;

        c = *s;
        *s++ = *--t;
        *t = c;
    }
    
}

char *itoa(int n, char *s)
{
    char *p;
    int sign;
    unsigned c;

    p = s;
    if ((sign = n) < 0)
        c = -n; // for the case: n = 1 <<31
    do
    {
        *p++ = (c % 10) + '0';
    } while ((c /= 10) > 0);
    if (sign < 0)
        *p++ = '-';
    *p = '\0';
    reverse(s);
    return s;
}

int strrindex(char *s, char *t)
{
    int i, j, k, last;
    last = -1;
    for(i=0; *(s+i)!='\0'; i++)
        for(j=i, k=0; *(s+j) == *(t+k) && *(t+k) != '\0'; j++, k++)
            ;
        if(k > 0 && *(t+k) == '\0')
            last = i;
    return last;
}

// #define NUMBER '0'

// int getch(void);
// void ungetch(int);

// int getop(char *s)
// {
//     int i, c;
//     static int pushback = -1;

//     if (pushback != -1)
//     {
//         c = pushback;
//         pushback = -1;
//     }
//     else
//         *s = getch();
//     while (c == ' ' || c == '\t')
//            *s = c = getch(); 
//     *(s+1) = '\0';
//     if (!isdigit(c) && c != '.')
//         return c;
//     i = 0;
//     if (isdigit(c))
//         while (isdigit(*++s = c = getch()))
//             ;
//     if (c == '.')
//         while (isdigit(*++s = c = getch()))
//             ;
//     *s = '\0';
//     // if (c != EOF)
//     //     ungetch(c);
//     return NUMBER;
// }


int main(void)
{
    char s[MAXSIZE];
    int len;
    // while (len = (getlineV1(s, MAXSIZE)) > 0)
    // {
    //     printf("input:%s\n", s);
    // }
    len = -12345;
    // *s = itoa(len);
    itoa(len, s);
    printf("Test itoa(%d) -> %s\n", len, s);
    len = atoi(s);
    printf("Test atoi(%s) -> %d\n", s, len);
}