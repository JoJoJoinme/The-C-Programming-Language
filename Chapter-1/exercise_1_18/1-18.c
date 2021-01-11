#include<stdio.h>

#define MAXSIZE 1000 /* Suppose the longest line contain 1000 words */

int getmyline(char line[], int limit);

void main()
{
    int len;
    char word[MAXSIZE];
    while((len = getmyline(word, MAXSIZE)) > 0)
	    printf("%s", word);
}

int getmyline(char s[], int lim)
{
    int i, c;
    for(i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n' || c == EOF) {
	for(; i > 0 && (c = s[i-1]) == '\t' || c == ' ' ; --i)
		;
	s[i] = '\n';
    }
    s[i+1] = '\0';
    return i;
}
