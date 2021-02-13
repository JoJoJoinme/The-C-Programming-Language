#include<stdio.h>
#include<float.h>
/* To Do:
 * Range of Float
 */
void main()
{
    int bitlen_char, bitlen_int, bitlen_short, bitlen_long;
    unsigned char uchar_max;
    unsigned short ushort_max;
    unsigned int uint_max;
    unsigned long ulong_max;
    char char_min, char_max;
    short short_min, short_max;
    int int_min, int_max;
    long long_min, long_max;
    bitlen_char = sizeof(char) * 8;
    bitlen_int = sizeof(int) * 8;
    bitlen_short = sizeof(short) * 8;
    bitlen_long = sizeof(long int) * 8;
    printf("bitlen of Char:%d\n", bitlen_char);
    printf("bitlen of Int:%d\n", bitlen_int);
    printf("bitlen of Short:%d\n", bitlen_short);
    printf("bitlen of Long:%d\n", bitlen_long);
    char_min = 1<<(bitlen_char-1);
    char_max = char_min-1;
    printf("Ranges of Char:%d~%d\n", char_min, char_max);
    uchar_max = (1<<bitlen_char)-1;
    printf("Ranges of unsigned Char:0~%u\n", uchar_max);
    short_min = 1<<(bitlen_short-1);
    short_max = short_min - 1;
    ushort_max = (1<<bitlen_short)-1;
    printf("Ranges of Short :%d~%d\n", short_min, short_max);
    printf("Ranges of unsigned Short:0~%u\n", ushort_max);
    int_min = 1<<(bitlen_int-1);
    int_max = int_min - 1;
    uint_max = int_max | int_min;
    printf("Ranges of Int :%d~%d\n",int_min, int_max);
    printf("Ranges of unsigned Int:0~%u\n", uint_max);
    long_min = 1L<<(bitlen_long-1);
    long_max = ~long_min;
    ulong_max = long_max | long_min;
    printf("Ranges of Long :%ld~%ld\n",long_min, long_max);
    printf("Ranges of unsigned long:0~%lu\n", ulong_max);
    printf("-----------------------------Float Number----------------------------------\n");
    int bitlen_float, bitlen_double;
    float float_min, float_max;
    double double_min, double_max;
    bitlen_float = sizeof(float) * 8;
    bitlen_double = sizeof(double) * 8;
    printf("bitlen of float:%d\n", bitlen_float);
    printf("bitlen of double:%d\n", bitlen_double);
    float_min = 0xFF7FFFFF;
    float_max = 0x7f7FFFFF;
    printf("Ranges of float:%g~%g\n", float_min, float_max);
    printf("float.h range of float:%g-%g\n",FLT_MIN, FLT_MAX);
    printf("float.h hex min val: 0x%08f, max val: 0x%08f", FLT_MIN, FLT_MAX); 

}
