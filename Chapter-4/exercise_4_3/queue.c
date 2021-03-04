#include <stdio.h>

#define MAXVAL 100

int tail = 0, head = 0;
char reverse_poland_queue[MAXVAL];

void queue_push(int c)
{
    if (tail < MAXVAL)
    {
        reverse_poland_queue[tail++] = c;
        // reverse_poland_queue[tail++] = ' ';
    }
    else
        printf("error: rp_queue full, can't push %c\n", c);

    reverse_poland_queue[tail] = '\0';
    int i = 0;
    while (reverse_poland_queue[i] != '\0')
    {
        printf("rp_queue[%d] -> %c, int:%d\n", i, reverse_poland_queue[i], reverse_poland_queue[i]);
        i += 1;
    }
    printf("current rp_queue:%s \n", reverse_poland_queue);
}

char queue_pop(void)
{
    if (head < tail)
        return reverse_poland_queue[head++];
    else
        printf("error: number queue empty, can't pop\n");
}