#include<stdio.h>

#define IN    1
#define OUT   0

void main()
{
    int c, len, i, j, max_num, cur_num;
    /* Suppose the longest word is 30 */
    char word[30];
    max_num = len = 0;
    for(i = 0; i < 30; i++)
    {
        word[i] = 0;
    }
    while((c = getchar()) != EOF)
    {
        if( c == ' ' || c == '\n' || c == '\t')
	{
	    ++word[len];
	    if(word[len] > max_num)
	        max_num = word[len];
	    len = 0;
	}
	else if((c >= 65 && c <= 90) || ( c >= 97 || c <= 122)) 
	    ++len;
    }
    /* Horizontal Histogram */
    printf("------------------------Horizontal Histogram:-------------------------------\n");
    for(i = 1; i < 30; i++)
    {
        printf("%3d:", i);
	for(j = 0; j < word[i]; j++)
	{
	    putchar('*');
	}
	putchar('\n');
    }
    /* To do:
     *    Vertical Histogram */
    printf("--------------------------Vertical Histogram:-------------------------------\n");
    for(cur_num = max_num; cur_num > 0; cur_num--)
    {
	printf("%3d|", cur_num);
        for(j = 0 ; j < 30 ; j++)
	{
	    if(word[j] >= cur_num)
                printf("** ");
	    else
		printf("   ");
	}
	putchar('\n');
    }
    printf("---------------------------------------------------------------------------------------------------\n");
    printf("   ");
    for(i = 1; i < 30; i++)
    {
        printf("%3d",i);
    }
}
