#include <stdio.h>
#define BUFFSIZE 100

char buf[BUFFSIZE];
int bufp = 0;
char queue_pop(void);

int getch(int queue_flag)
{
    if(queue_flag != 1)
        return (bufp > 0) ? buf[--bufp] : getchar();
    return (bufp > 0) ? buf[--bufp] : queue_pop();
}

void ungetch(int c)
{
    if (bufp >= BUFFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}