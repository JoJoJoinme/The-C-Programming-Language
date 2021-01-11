#include <stdio.h>

void main()
{
    int c, i, j;
    /* presume the longest word is 19 */
    char word[128];

    for (i = 0; i < 128; i++)
    {
        word[i] = 0;
    }
    while ((c = getchar()) != EOF)
    {
        word[c] += 1;
    }
    for (i = 0; i < 128; i++)
    {
        putchar(i);
        for (j = 0; j < word[i]; j++)
        {
            putchar('-');
        }
        putchar('\n');
    }
}
