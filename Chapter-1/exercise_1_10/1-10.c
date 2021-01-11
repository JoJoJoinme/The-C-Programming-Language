#include<stdio.h>

void main()
{
    int c;
    c = 0;
    while((c = getchar()) != EOF)
    {
      
       if(c == '\\' || c == '\t' || c == ' ')
       {
           putchar('\\');
	   switch (c)
	   {
	        case '\\':
	             putchar('\\');
		     break;
		case '\t':
		     putchar('t');
		     break;
		case ' ':
		     putchar('b');
	   	
	   }
	
       }
       else
           putchar(c);
    }
}
