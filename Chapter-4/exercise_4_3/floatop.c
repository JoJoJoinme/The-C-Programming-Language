// #include <stdio.h>
#include <math.h>

int floatdecimallen(float number)
{
    int len = 0;
    float thresold = 0.000000001, num = fabs(number);
    while (num - round(num) > thresold)
    {
        len += 1;
        num = (num - round(num)) * 10;
        thresold *= 10;
    }
    return len;
}

// float fabs(float number)
// {
//     return number > 0.0 ? number : number * -1;
// }
