#include <stdio.h>
#include <ctype.h>

double atof_extend(char s[])
{
    int i, sign, exp_sign = 1, exp_power = 0;
    double val, power;
    for (i = 0; isspace(s[i]); i++)
        i++;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = val * 10.0 + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        if (s[++i] == '-')
        {
            exp_sign = -1;
            i++;
        }
        while (isdigit(s[i]))
        {
            exp_power = 10 * exp_power + (s[i] - '0');
            i++;
        }
        // printf("exp_power -> %d, s[i] -> %c\n", exp_power, s[i]);

        while (exp_power)
        {
            (exp_sign == -1) ? power *= 10 : (power /= 10);
            --exp_power;
        }
    }
    return sign * val / power;
}
