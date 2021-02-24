#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXSIZE 200

int samecase(char s1, char s2)
{
    if((isupper(s1) && isupper(s2)) || (islower(s1) && islower(s2)) || (isdigit(s1) && isdigit(s2)))
        return 1;
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j;
    char prev, back;
    for(i = 0, j = 0;i < strlen(s1); i++)
    {
        if (s1[i] == '-' && i > 0)
        {
            if(samecase(s1[i-1], s1[i+1]))
            {
                prev = s1[i-1];
                back = s1[i+1];
                while(prev <= back)
                {
                    s2[j++] = prev;
                    prev++;
                }
            }
        }
        
    }
}

int main()
{
    char s1[] = "a-z";
    char s2[MAXSIZE];
    printf("Original string: %s\n", s1);
    expand(s1, s2);
    printf("expand string: %s\n", s2);
    char s3[] = "-a-z0-9\0";
    printf("Original string: %s\n", s3);
    expand(s3, s2);
    printf("expand string: %s\n", s2);


}