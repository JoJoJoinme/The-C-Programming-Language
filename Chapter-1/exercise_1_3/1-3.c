#include<stdio.h>

void main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Float Version of Temperature Converter\n");
    while(fahr < upper)
    {
    	celsius =  5 * (fahr - 32) / 9;
	printf("%3.1f\t%6.1f\n", fahr, celsius);
	fahr = fahr + step;
    }
}
