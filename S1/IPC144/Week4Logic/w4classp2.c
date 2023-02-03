#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    int i=0;
    
    //while
    while (i < 5)
    {
        printf("while: i = %d\n",i);
        i++;
    }

    //do-while
    do
    {
        printf("do-while: i = %d\n",i);
        i--;
    } while (i > 0);

    //for
    for (i = 0; i < 5; i++)
    {
        printf("for-loop: i = %d\n",i);
    }
    
}