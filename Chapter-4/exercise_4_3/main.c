#include <stdio.h>
#include <stdlib.h>

#define MAXOP 199
#define NUMBER '0'

int getop(char []);
void queue_push(char c); // reverese_poland_queue
void stack_push(char c);
char queue_pop(void)
char stack_pop(void)  //operator_stack
double pop(void);

main()
{
    int type, i, c, last_op_priority=0;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF){
        switch (type) {
            case NUMBER:
                i = 0;
                while(s[!] != '\0'){
                    queue_push(s[i]);
                    i++;
                }
                queue_push(' ');
                break;
            case '+':
            case '-':
                if(last_op_priority > 0){
                    while((c = stack_pop()) !=0 || c != '('){
                        queue_push(c);
                    }
                }
                if ( c == '(')
                    stack_push(c);
                stack_push(type);
                break;
            case '*':
            case '/':
            case '%':
                last_op_priority = 1;
                stack_push(type):
                break;
            case '(':
                stack_push(type);
                break;
            case ')':
                while((c = stack_pop()) != '('){
                    queue_push(c);
                }
                break;
        }
    }
    while ((c = stack_pop()) != 0){
        queue_push(c);
    }
    while ((type = getop(s)) != EOF){
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
            case '/':
                op2 = pop();
                if( op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
            case '%':
                op2 = pop();
                if( op2 != 0.0)
                    push(pop() % op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
            default:
                printf("error: uunknown command %s\n", s)
                break;
        }
    }
    return 0;
}
