#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAXLEN 500
#define MAXLINE 1000
#define MAXCHAR MAXLINE * MAXLEN

int readlines(char *lineptr[], int maxline, char linbuf[]);
void writelines(char *lineptr[], int nlines);
int getmyline(char *s, int lim);

int main(int argc, char *argv[])
{
    char *lineptr[MAXLINE], linebuf[MAXCHAR];
    int n, nlines;
    if (argc == 1)
        n = 10;
    else if (argc == 2)
        n = atoi(++(*++argv));
    else
    {
        printf("Too many arguments:\n, %s", *argv);
        return -1;
    }
    printf("Please input lines:\n");
    if ((nlines = readlines(lineptr, MAXLINE, linebuf)))
    {
        printf("Print last %d lines:\n", n);
        // reverse(lineptr);
        writelines(lineptr + (nlines - n), n);
    }
    else
    {
        printf("Input too big:\n");
        return -1;
    }
    return 0;
}

int readlines(char *lineptr[], int maxlines, char *linebuf)
{
    int len, nlines = 0;
    char *p, line[MAXLEN];

    p = linebuf;
    while ((len = getmyline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p + len > linebuf + MAXCHAR)
            return -1;
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

int getmyline(char *s, int lim)
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

void writelines(char *lineptr[], int n)
{
    while (--n >= 0)
        printf("%s\n",*lineptr++);
    
}