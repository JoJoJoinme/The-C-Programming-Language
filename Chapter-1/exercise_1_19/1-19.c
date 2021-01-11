#include<stdio.h>

#define MAXSIZE 1000 /* Suppose the longest string get length 1000 */

int getmyline(char line[], int limit);
void my_reverse(char src[], int len);

void main()
{
    int len;
    char line[MAXSIZE];
    while ((len = getmyline(line, MAXSIZE)) > 0)
    {
         my_reverse(line, len-2);
	 printf("%s", line);
    }
}

int getmyline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
         s[i] = c;
    if (c == '\n')
    {
        s[i] = '\n';
	++i;
    }
    s[i] = '\0';
    return i;
}

void my_reverse(char line[], int len)
{
     int i;
     char c;
     for(i = 0; i < len; ++i, --len)
     {
	 c = line[i];
	 line[i] = line[len];
	 line[len] = c;
     }
}
