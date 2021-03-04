#include <stdio.h>

#define MAXVAL 100

int rp_sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (rp_sp < MAXVAL)
        val[rp_sp++] = f;
    else
        printf("error: reverse poland stack full, can't push %g\n",f);
}

double pop(void)
{
    if (rp_sp > 0)
        return val[--rp_sp];
    else {
        printf("error: reverse poland stack empty\n");
        return 0.0;
    }
}