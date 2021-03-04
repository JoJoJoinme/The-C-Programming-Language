#include <stdio.h>

// #define swap(t, x, y)  (t) y = ((t) x) ^ ((t) y), (t) x =  ((t) x) ^ ((t) y), (t) y = ((t) y) ^ ((t) x)
#define SWAP(t, x, y) \
{\
    t p;\
\
    p = (t) x;\
    x = (t) y;\
    y = (t) p;\
\
}

void main()
{
    int x1 = 1 << 15, x2 = 1 << 16;
    printf("before: sizeof(x1) -> %lu\n", sizeof(x1));
    printf("before swap: x1 -> %d, x2 -> %d\n", x1, x2);
    SWAP(char, x1, x2);
    printf("after: sizeof(x1) -> %lu\n", sizeof(x1));
    printf("after swap: x1 -> %d, x2 -> %d\n", x1, x2);
    // printf("after swap: sizeof(x1) -> %lu\n", sizeof(x1));
}