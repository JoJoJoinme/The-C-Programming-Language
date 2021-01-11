#include<stdio.h>

#define IN 1
#define OUT 0

void main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF)
    {
        ++nc;
	if(c == '\n')
	    ++nl;
	if(c == ' ' || c == '\t' || c == '\n')
	    state = OUT;
	else if(state == OUT)
	{
	    ++nw;
	    putchar('\n');
	    state = IN;
	}
	putchar(c);
    }
    printf("nl:%d\nnw:%d\nnc:%d", nl, nw, nc);
}
