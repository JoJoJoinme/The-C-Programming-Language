#include <string.h>
#include <stdio.h>

#define MAXLINES 5000
#define MAXCHAR 3000

char *lineptr[MAXLINES];
char linebuf[MAXCHAR];

int readlines(char *lineptr[], int nlines, char linebuf[]);
void writelines(char *lineptr[], int nlines);

void quicksort(char *lineptr[], int left, int right);
void swap(char *lineptr[], int i, int j);

int getmyline(char *, int);
char *alloc(int);

int main(void)
{
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES, linebuf)) < 5000)
    {
        printf("begin quicksort!\n");
        quicksort(lineptr, 0, nlines-1);
        printf("begin writelines\n");
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input to big to sort\n");
        return 1;
    }
}


#define MAXLEN 1000

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
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i = 0;

    while (nlines--)
        printf("%s\n", lineptr[i++]);
    
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

void quicksort(char *lineptr[], int left, int right)
{
    int i, last;

    if (left >= right)
        return ;
    
    // printf("swap begin %d, %d\n", left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if(strcmp(lineptr[i], lineptr[left]) < 0)
            swap(lineptr, ++last, i);
    swap(lineptr, left, last);
    quicksort(lineptr, left, last-1);
    quicksort(lineptr, last+1, right);
}

void swap(char *lineptr[], int i, int j)
{
    char *temp;
    temp = lineptr[i];
    lineptr[i] = lineptr[j];
    lineptr[j] = temp;
}