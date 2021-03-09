#include <stdio.h>

int strend(char *s, char *t)
{
    int j;
    while (*s)
        s++;
    for (j = 0; *t; j++)
        t++;
    while (*--s == *--t && j--)
        if(j == 0)
            return 1;
    return 0;
    
}

int main(void)
{
    char *s = "abcde";
    char *t = "cde";
    printf("res:%d\n", strend(s, t));
    t = "abc";
    printf("res:%d\n", strend(s, t));
    t = "abcakwdija";
    printf("res:%d\n", strend(s, t));
    t = "mabcde";
    printf("res:%d\n", strend(s, t));

}