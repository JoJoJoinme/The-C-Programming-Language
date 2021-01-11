#include<stdio.h>

void main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -18;
    upper = 138;
    step = 20;

    celsius = lower;
    while(celsius < upper)
    {
	fahr = celsius * 9 / 5 + 32;
	printf("%3f\t%6f\n", fahr, celsius);
	celsius = celsius + step;
    }
}
