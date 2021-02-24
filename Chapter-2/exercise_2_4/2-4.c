#include <stdio.h>
#include <string.h>

#define MAXSIZE 128
#define MAXWORD 1000

/* delete all characters which comes from s1 in s2,*/
void squeeze(char s1[], char s2[]);

/* delete all c in src */
void squeeze_one(char src[], int c);

void unique_string(char src[])
{
    int i, j;
    size_t len;
    len = strlen(src);
    printf("Unque len is:%ld\n", len);
    int table[MAXSIZE] = {0};
    char dest[len];
    for (i = 0, j = 0; i < len; i++)
    {
        if (table[src[i]] == 0)
        {
            table[src[i]]++;
            dest[j++] = src[i];
        }
    }
    dest[j] = '\0';
    i = 0;
    while (dest[i] != '\0')
    {
        src[i] = dest[i];
        i++;
    }
    src[i] = '\0';
    printf("In unique dest :%s\n", dest);
    //   squeeze(dest, s2);
}

void squeeze_one(char src[], int c)
{
    int i, j;
    for (i = 0, j = 0; src[i] != '\0'; i++)
        if (src[i] != c)
            src[j++] = src[i];
    src[j] = '\0';
}

void squeeze(char s1[], char s2[])
{
    size_t len_s1, len_s2;
    int i, j;
    len_s1 = strlen(s1);
    len_s2 = strlen(s2);
    unique_string(s1);
    printf("dest str:%s, len:%ld\n", s1, len_s1);
    for (i = 0; i < len_s1; i++)
        squeeze_one(s2, s1[i]);
}

void get_input(char src[])
{
    int i;
    char c;
    for (i = 0; i < MAXWORD - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        src[i] = c;
    }
    if (c == '\n')
        src[i++] = '\n';
    src[i] = '\0';
    printf("input got: %s\n", src);
}

void main()
{
    char s1[MAXSIZE], s2[MAXWORD];
    printf("Plase input s1:\n");
    get_input(s1);
    printf("Plase input s2:\n");
    get_input(s2);
    //   unique_string(s1, s2);
    squeeze(s1, s2);
    printf("s2 after squeeze get:%s", s2);
}
