#include <stdio.h>

#define MAXVAL 100

int sp = 0;
char operand_stack[MAXVAL];

void stack_push(int c)
{
    if (sp < MAXVAL)
        operand_stack[sp++] = c;
    else
        printf("error: stack full, can't push %c\n", c);
}

char stack_pop(void)
{
    if(sp > 0)
        return operand_stack[--sp];
    else
        printf("error: stack empty, can't pop\n");
    return 0;
}