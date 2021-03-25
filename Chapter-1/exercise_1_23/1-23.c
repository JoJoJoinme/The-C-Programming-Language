#include <stdio.h>

// int single_quote = 1; // default: unquoted
int quoted = 1; // default: unquoted
int flag = 0;   // default: uncomment

int main(void)
{
    int eof, c, next, splash_flag, star_flag;
    eof = splash_flag = star_flag = 0;
    next = -2;
    while ((eof == 0) && ((c = getchar()) != EOF))
    {
        if (!flag) // uncomment
        {
            if (c == '\'' || c == '\"')
                quoted = !quoted;
            else if (c == '/')
            {
                if ((next = getchar()) == '/')
                    splash_flag = 1;
                else if (next == '*')
                    star_flag = 1;
                else if (next == EOF) // EOF
                    eof = 1;
            }
            if (!quoted)
            {
                next = c;
                do
                    putchar(c);
                while ((c = getchar()) != EOF && c != next);
                if (c == next)
                    putchar(c);
                else 
                    eof = 1;
                quoted = !quoted;
            }
            else
            {
                flag = splash_flag + star_flag;
                if (flag == 0)
                {
                    putchar(c);
                    if (next != -2)
                        putchar(next);
                }
            }
        }
        else
        {
            if (c == '*')
                if ((next = getchar()) == '/')
                    star_flag = splash_flag = 0;
                else if (next == EOF)
                    eof = 1;
            if (c == '\n' || next == '\n')
                splash_flag = 0;
            flag = star_flag + splash_flag;
        }
        // printf("\nflag status:\nstar_flag:%d splash_flag:%d\n", star_flag, splash_flag);
        // printf("eof status:%d\n", eof);
        next = -2;
    }
}

/* 默认为未注释状态
 * 情况处理：
 *    * 未注释：读取一个字符，输出一个字符
 *    *   注释：读取字符，不输出
 * 
 * 注释状态细分：
 *   1. "//"：则从此刻开始，直至遇到'\n'结束注释
 *   2. "/*": 从此刻开始，直至反向结束
 * 
 */

// Specail Case:
/*/dd
/* /*/
