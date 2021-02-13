#include<stdio.h>
#include<string.h>


void lower(char src[])
{
    for(int i=0;i<strlen(src);i++){
        src[i] = src[i] >= 65 && src[i] <= 90 ? src[i] + 32: src[i];
    }
}


int main(int argc, char *argv[])
{
    int counter;
    char src[] = "ABCDEFGwtr123\0";
    printf("input:%s\n", src);
    lower(src);
    printf("lower ouput:%s\n",src);
    printf("Program name is:%s", argv[0]);
    printf("Number of Arguments passed:%d\n", argc);
    printf("------------Following Are Command Line Arguments Passed------------\n");
    if(argc==1)
        printf("No Extra Command line arguments input\n");
    if(argc>=2){
        for(counter=0;counter<argc;counter++){
            printf("arg[%d]:%s\n", counter, argv[counter]);
        }
    }
//    src = *argv[2];
//    lower(src);
//    printf("Res:%s", src);
    return 0;
}
