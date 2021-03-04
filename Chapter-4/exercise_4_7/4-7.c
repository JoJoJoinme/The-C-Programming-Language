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
int getop(char s[]);
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

int main()

{
    int i, type;
    double op1, op2;
    char s[MAXOP];
    double variables[26];

    for(i = 0; i < 26; i++)
        variables[i] = 0.0;

    while ((type = getop(s)) != EOF)

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

int getop(char s[])
{
    int c, i, symbol;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (c == '<' || c == '>')
    {
        s[0] = getch();
        return c;
    }
    i = 0;
    if (isalpha(c))
    {
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        switch (sumofchar(s))
        {
            case 330:  // sin, s=115, i=105, n=110
                /* code */
                symbol = SIN;
                break;

            case 326:  //cos s=115, o=111, c=100
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
            return c;
        i = 0;
        if (isdigit(c))
            while (isdigit(s[++i] = c = getch()))
                ;
        if (c == '.')
            while (isdigit(s[++i] = c = getch()))
                ;
        symbol = NUMBER;
    }
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return symbol;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)

{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)

{
    if (bufp >= BUFSIZE)

        printf("Error: Too many characters!\n");

    else

        buf[bufp++] = c;
}

/* however, it's unused */
void ungets(char s[])
{
    int i;
    for(i = 0; s[i] != '\0'; i++)
        ungetch(s[i]);
}

int sumofchar(char s[])
{
    int sum=0;
    printf("sumofchar, input:%s\n", s);
    for(int i = 0; s[i] != '\0'; i++)
    {
        printf("char:s[%d] -> %c, int: ->%d\n", i, s[i], s[i]);
        sum += (int) s[i];
    }
    printf("sum:%d\n", sum);
    return sum;
}

