#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[], int queue_flag);
int floatdecimallen(float number);
void queue_push(char c); // reverese_poland_queue
void stack_push(char c);
void push(double c);
char queue_pop(void);
int stack_pop(void); //operator_stack
double pop(void);

int main()
{
    int i, c, type, input_flag = 0, queue_flag = 0, last_op_priority = 0;
    double op2, op1;
    char s[MAXOP];

    printf("----------------------Comes to Resort operation order------------------------\n");
    while ((type = getop(s, queue_flag)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            i = 0;
            while (s[i] != '\0')
            {
                queue_push(s[i]);
                i++;
            }
            queue_push(' ');
            break;
        case '+':
        case '-':
            if ((c = stack_pop()) != 0 && c != '(')
            {
                printf("before character: %c, int:%d\n", c, c);
                queue_push(c);
                queue_push(' ');
            }
            if (c == '(')
                stack_push(c);
            if (last_op_priority > 0)
            {
                while ((c = stack_pop()) != 0 && c != '(')
                {
                    queue_push(c);
                    queue_push(' ');
                }
                if (c == '(')
                    stack_push(c);
            }
            stack_push(type);
            break;
        case '*':
        case '/':
        case '%':
            if ((c = stack_pop()) == '/' || c == '*' || c == '%')
                queue_push(c);
            else
            {
                if (c != 0)
                    stack_push(c);
            }
            last_op_priority = 1;
            stack_push(type);
            break;
        case '(':
            stack_push(type);
            break;
        case ')':
            while ((c = stack_pop()) != '(')
            {
                queue_push(c);
                queue_push(' ');
            }
            break;
        case '\n':
            while ((c = stack_pop()) != 0)
                queue_push(c);
            input_flag = 1;
            queue_push('\n');
            break;
        default:
            printf("error: input unknown command %s\n", s);
            break;
        }
        if (input_flag)
            break;
    }
    queue_flag = 1;
    printf("----------------------Comes to Calculate------------------------\n");
    input_flag = 0;
    while ((type = getop(s, queue_flag)) != EOF)
    {
        printf("type get: %d, char: %c\n", type, type);
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            printf("comes to +\n");
            push(pop() + pop());
            break;
        case '*':
            printf("comes to *\n");
            push(pop() * pop());
            break;
        case '-':
            printf("comes to -\n");
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            printf("comes to /\n");
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            printf("comes to mod \n");
            op2 = pop();
            if (op2 != 0.0)
            {
                push(fmod(pop(), (int)op2));
            }
            else
                printf("error: zero mod divisor\n");
            break;
        case '\n':
            printf("comes to res\n");
            printf("\t%.8g\n", pop());
            input_flag = 1;
            break;
        default:
            printf("error: rp_stack unknown command %s\n", s);
            break;
        }
        if (input_flag)
            break;
        // }
    }
    return 0;
}
