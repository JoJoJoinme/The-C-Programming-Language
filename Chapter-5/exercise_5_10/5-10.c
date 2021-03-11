#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Variables are the 26 letters of alphabet, which must be lower case. Use
  * >x to save the top of stack into variable x, and <x to push it back
 */

#define MAXOP 100
#define NUMBER '0'

void clear_stack(void);
void push(double f);
double pop(void);
int getop(char s[], char *argv);
int sumofchar(char s[]);

enum
{
    SIN,
    COS,
    EXP,
    POW,
    SQRT,
    UNKNOWN
};

int pushback = -1;

int main(int argc, char *argv[])
{
    int i, type;
    double op1, op2;
    char s[MAXOP];
    double variables[26];

    char **p;
    p = argv;
    for(int j=0; j < argc; j++)
        printf("The %d arg: %s\n",j+1, *p++);
    // printf("input argument:%d", argc);


    for (i = 0; i < 26; i++)
        variables[i] = 0.0;

    while (--argc > 0 && *++argv)
        while ((type = getop(s, *argv)) != EOF && type != '\0')
            switch (type)
            {

            case NUMBER:

                push(atof(s));
                break;

            case '<':
            case '>':
                if ((i = s[0] - 'a') < 0 || i > 26)
                    printf("Incorrect Input of char:%c\n", s[0]);
                else
                {
                    if (type == '>')
                        variables[i] = pop();
                    else
                        push(variables[i]);
                    // printf("top of stack:%f\n", variables[i]);
                }
                break;

            case SIN:
                push(sin(pop()));
                break;

            case COS:
                push(cos(pop()));
                break;

            case POW:
                op2 = pop();
                push(pow(pop(), op2));
                break;

            case EXP:
                push(exp(pop()));
                break;

            case SQRT:
                push(sqrt(pop()));
                break;

            case '!':

                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;

            case '&':

                clear_stack();
                break;

            case '+':
            case '*':

                if (type == '+')

                    push(pop() + pop());

                else

                    push(pop() * pop());

                break;

            case '-':

                op2 = pop();
                push(pop() - op2);
                break;

            case '/':
            case '%':

                if ((op2 = pop()) != 0.0)
                {

                    if (type == '/')

                        push(pop() / op2);

                    else
                    {

                        op1 = pop();
                        push(op1 - op2 * ((int)(op1 / op2)));
                    }
                }
                else

                    printf("Error: Zero divisor!\n");

                break;

            case '=':
            case '\n':

                printf("\t%.8g\n", op1 = pop());
                if (type == '=')

                    push(op1);

                break;

            default:

                printf("Error: Unknow command %s!\n", s);
                break;
            }

    printf("\t%.8g\n", pop());
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void clear_stack(void)

{
    sp = 0;
}

void push(double f)

{
    if (sp < MAXVAL)

        val[sp++] = f;

    else

        printf("Error: Stack is full, cannot push %g!\n", f);
}

double pop(void)

{
    if (sp > 0)

        return val[--sp];

    else
    {

        printf("Error: Stack is empty, cannot pop!\n");
        return 0.0;
    }
}

int getch(void);
void ungetch(int c);

int getop(char s[], char *argv)
{
    int c, i, symbol;

    while ((s[0] = c = (pushback != -1 ? getch() : *argv++)) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (c == '\0')
        return c;
    if (c == '<' || c == '>')
    {
        s[0] = *argv++;
        return c;
    }
    i = 0;
    if (isalpha(c))
    {
        while (isalpha(s[++i] = c = *argv++))
            ;
        s[i] = '\0';
        switch (sumofchar(s))
        {
        case 330: // sin, s=115, i=105, n=110
            /* code */
            symbol = SIN;
            break;

        case 326: //cos s=115, o=111, c=100
            symbol = COS;
            break;

        case 342: //pow p=112, o=111, w=119
            symbol = POW;
            break;

        case 333: //exp e=101, x=120, p=112
            symbol = EXP;
            break;

        case 458: //SQRT s=115, q=113, r=114, t=116
            symbol = SQRT;
            break;
        default:
            printf("unknown inputs:%s\n", s);
            break;
        }
    }
    else
    {
        if (!isdigit(c) && c != '.')
        {
            symbol = c;
            c = *argv++;
        }
        else
        {
            i = 0;
            if (isdigit(c))
                while (isdigit(s[++i] = c = *argv++))
                    ;
            if (c == '.')
                while (isdigit(s[++i] = c = *argv++))
                    ;
            symbol = NUMBER;
        }
    }
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return symbol;
}

int getch(void)

{
    if (pushback != -1)
    {
        int t;
        t = pushback;
        pushback = -1;
        return t;
    }
    return getchar();
}

void ungetch(int c)

{
    if (pushback != -1)
        printf("too many characters\n");
    else
        pushback = c;
}

int sumofchar(char s[])
{
    int sum = 0;
    printf("sumofchar, input:%s\n", s);
    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("char:s[%d] -> %c, int: ->%d\n", i, s[i], s[i]);
        sum += (int)s[i];
    }
    printf("sum:%d\n", sum);
    return sum;
}
