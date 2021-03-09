#include <stdio.h>

#define MAXSIZE 100

void strncpy(char *s, char *t, int n)
{
    while (n--)
    {
        if (*t == '\0')
            while (n--)
                *s++ = '\0'; /* pad \0 when n > len(t) */
        else
            *s++ = *t++;
    }
    *s++ = '\0';
    
}

void strncat(char *s, char *t, int n)
{
    while (*s)
        s++;
    while (n--)
    {
        if (*t == '\0')
            while (n--)
                *s++ = '\0';
        else
            *s++ = *t++;
    }
    *s++ = '\0';
}

int strncmp(char *s, char *t, int n)
{
    // while (n--)
    // {

    // }
    for (;n > 0 && *s == *t;n--, s++, t++)
        if (n == 1)
            return 0;
    return *s - *t;
}

int main()
{
    char s[MAXSIZE] = "abc";
    char *t = "opq";
    int n = 2;
    printf("strncat(%s, %s, %d)\n", s, t, n);
    strncat(s, t, n);
    printf("res: -> %s\n", s);
    printf("strncmp(%s, %s, %d)\n", s, t, n);
    printf("res: -> %d\n", strncmp(s, t, n));
    printf("strncpy(%s, %s, %d)\n", s, t, n);   
    strncpy(s, t, n);
    printf("res: -> %d\n", strncmp(s, t, n));
}