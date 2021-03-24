#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int column, tab;
    char *p;

    while (--argc && (p = *++argv))
    {
        printf("The %d arguments: %s\n", argc, p);
        char c = *p++;
        if (c == '-')
            column = atoi(p);
        else if (c == '+')
            tab = atoi(p);
        else
            printf("Unknown arguments: %s\n", p);
    }    
    printf("Columns:%d, Tab:%d\n",column, tab);

}