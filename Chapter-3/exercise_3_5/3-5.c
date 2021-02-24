#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

void reverse(char s[])
{
    int i, j, c;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

void itob(int n, char s[], int base)
{
    // Integer to string on base
    // For example:
    // itob(23, 2)
    char arr[base];
    int sign, i;
    unsigned c;
    
    for(i = 0; i < base; i++)
    {
        if(i >= 10)
            arr[i] = 'A' + i - 10;
        else{
            arr[i] = i + '0';
        }
    }

    c = n;
    if ((sign = n) < 0)
        c = -n;
    i = 0;
    do
    {
        s[i++] = arr[c % base];
    } while ((c /= base) > 0);
    
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    int n, base;
    char s[MAXSIZE];
    base = 10;
    n = 1 << 31;
    itob(n, s, base);
    printf("itob(%d, base->%d) return:\n %s\n", n, base, s);
    n = 23;
    base = 16;
    itob(n, s, base);
    printf("itob(%d, base->%d) return:\n %s\n", n, base, s);
    base = 8;
    itob(n, s, base);
    base = 2;
    itob(n, s, base);
    printf("itob(%d, base->%d) return:\n %s\n", n, base, s);

}
