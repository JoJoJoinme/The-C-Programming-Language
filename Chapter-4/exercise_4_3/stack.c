#include <stdio.h>

#define MAXVAL 100

int sp = 0;
char operand_stack[MAXVAL];

void stack_push(char c)
{
    printf("stack push: %c, int:%d\n", c, c);
    if (sp < MAXVAL)
    {
        operand_stack[sp++] = c;
        operand_stack[sp] = '\0';
        for(int i=0; operand_stack[i] != '\0'; i++)
            printf("operand stack[%d], char:%c, int: %d\n",i, operand_stack[i], operand_stack[i]);
    }
    else
        printf("error: operation stack full, can't push %c\n", c);
}

int stack_pop(void)
{
    if(sp > 0)
    {
        int i = operand_stack[--sp];
        printf("stack_pop: %c, %d\n", i, i);
        return i;
    }
    printf("error: operation stack empty, can't pop\n");
    return 0;
}