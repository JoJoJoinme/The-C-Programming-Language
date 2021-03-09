#include <stdio.h>

#define MAXSIZE 100

void mystrcat(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}

int main()
{
    char s[MAXSIZE] = "Hello, ";
    char *m = "Tom,";
    char *t = "world!";
    printf("original: %s\n", s);
    mystrcat(s, t);
    mystrcat(s, m);
    printf("after: %s\n", s);

}