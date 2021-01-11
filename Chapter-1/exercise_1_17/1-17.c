#include<stdio.h>

#define MAXSIZE 1000 /* Suppose the longest line contain 1000 words */

int getmyline(char line[], int limit);

void main()
{
    int len;
    char word[MAXSIZE];
    while((len = getmyline(word, MAXSIZE)) > 80)
	    printf("%s", word);
}

int getmyline(char s[], int lim)
{
    int i, c;
    for(i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n') {
	s[i] = '\n';
	++i;
    }
    s[i] = '\0';
    return i;
}
