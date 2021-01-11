#include<stdio.h>

#define MAXLINE 1000	/*   The longest of input */

int getmyline(char line[], int maxline);
void copy(char to[], char from[]);

void main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    while ((len = getmyline(line, MAXLINE)) > 0)
    {
	    copy(longest, line); 
	    printf("%s", longest);
    }
	
}

int getmyline(char s[], int lim)
{
    int c, i;
    for(i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n') {
	s[i] = '\n';
	++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0')
    	++i;
}

