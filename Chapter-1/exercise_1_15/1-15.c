#include<stdio.h>

float temp_convert(int fahr);


void main()
{
    int fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while(fahr < upper)
    {
	printf("%3d\t%6f\n", fahr, temp_convert(fahr));
	fahr = fahr + step;
    }
}

float temp_convert(int fahr)
{
    return 5 * (fahr - 32) / 9;
}
