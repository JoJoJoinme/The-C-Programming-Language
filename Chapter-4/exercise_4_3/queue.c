#include <stdio.h>

#define MAXVAL 100

int tail, head;
char reverse_poland_queue[MAXVAL];

head = tail = 0

void queue_push(int c)
{
    if (tail < MAXVAL)
        reverse_poland_queue[tail++] = c;
    else
        printf("error: queue full, can't push %c\n", c);
}

char queue_pop(void)
{
    if(head < tail)
        return reverse_poland_queue[head++];
    else
        printf("error: queue empty, can't pop\n");
}