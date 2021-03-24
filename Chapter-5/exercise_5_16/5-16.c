#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 100
#define MAXCHAR MAXLINES *MAXLEN

char *lineptr[MAXLINES];
char linebuf[MAXCHAR];

int readlines(char *lineptr[], int nlines, char linebuf[]);
void writelines(char *lineptr[], int nlines);

int getmyline(char *s, int lim);

void quicksort(void *lineptr[], int left, int right,
               int (*comp)(void *, void *));

void swap(void *lineptr[], int i, int j);

char *strtolower(char *src);

int reversed = 1;  /* Ascending sort , default */
int fold = 0;      /* Case Sesstive */
int directory = 0; /* not directory order */
int numeric = 0;

int numcmp(char *, char *);
int mystrcmp(char *, char *);

/*Sort input lines */
int main(int argc, char *argv[])
{
    int nlines, c;
    while (--argc > 0 && (*++argv)[0] == '-')
    {
        while (c = *++argv[0])
        {
            switch (c)
            {
            case 'r':
                reversed = -1;
                break;
            case 'n':
                numeric = 1;
                break;
            case 'f':
                fold = 1;
                break;
            case 'd':
                directory = 1;
                break;
            default:
                printf("Sort: illegal option: %c\n", c);
                argc = 0;
                break;
            }
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES, linebuf)) >= 0)
    {
        quicksort((void **)lineptr, 0, nlines - 1,
                  (int (*)(void *, void *))(numeric ? numcmp : mystrcmp));
        printf("----------------------sorted input-----------------------\n");
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big too sort");
        return -1;
    }
}

void quicksort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (reversed * (*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    quicksort(v, left, last - 1, comp);
    quicksort(v, last + 1, right, comp);
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int mystrcmp(char *s1, char *s2)
{
    int a, b;
    for (;;)
    {
        if (directory)
        {
            do
                a = *s1++;
            while (!isalnum(a) && !isspace(a) && a != '\0');
            
            do
                b = *s2++;
            while (!isalnum(b) && !isspace(b) && b != '\0');
        }
        else
        {
            a = *s1++;
            b = *s2++;
        }
        if (fold)
        {
            a = tolower(a);
            b = tolower(b);
        }
        if (a != b)
            break;
        else if (a == '\0')
            return 0;
    }
    return a - b;
}

void swap(void *v[], int i, int j)
{
    void *p;
    p = v[j];
    v[j] = v[i];
    v[i] = p;
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
    while (n--)
        printf("%s\n", *lineptr++);
}

char *strtolower(char *src)
{
    char *p;
    p = src;
    for (; *src != '\0'; src++)
        *p++ = tolower(*src);
    return p;
}