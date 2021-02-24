#include <stdio.h>
#include <string.h>
#define MAXSIZE 1000


void escape(char src[], char dest[])
{
    int len = strlen(src);
    char backslash = '\\';
    for(int i=0, j=0; i<len; i++)
    {
        switch (src[i])
        {
        case '\t':
            dest[j++] = backslash;
            dest[j++] = 't';
            break;
        case '\n':
            dest[j++] = backslash;
            dest[j++] = 'n';
            break;
        default:
            dest[j++] = src[i];
            break;
        }
    }
}

int main()
{
    printf("\\t shows: \t\n");
    char src[MAXSIZE], dest[MAXSIZE];
    char c;
    for(int i = 0; i < MAXSIZE && (c = getchar())!=EOF;i++)
    {
        src[i] = c;
    }
    escape(src, dest);
    printf("Original Input: %s\n", src);
    printf("After Escape: %s\n", dest);
    return 0;
}
