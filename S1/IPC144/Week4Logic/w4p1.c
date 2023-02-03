/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  :CHI-WEI PERNG
Student ID#:121967228
Email      :cperng@myseneca.ca
Section    :NCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    char character;
    int times, c;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");
    printf("\n");
    
    do{
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf("%c%d%*c",&character ,&times);

        if(character == 'D' || character == 'W' || character == 'F' || character =='Q'){
            switch (character)
            {
                case 'D':
                case 'W':
                case 'F':
                    if(times >= 3 && times <= 20){
                        if(character == 'D')
                        {
                            printf("DO-WHILE: ");
                        }else if(character == 'W')
                        {
                            printf("WHILE   : ");
                        }else if(character == 'F')
                        {
                            printf("FOR     : ");
                        }
                        for (c = 1; c < times+1; c++)
                        {
                            printf("%c", character);
                        }
                        printf("\n");
                    }else{
                        printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
                    }
                    break;
                case 'Q':
                    if(times == 0){
                        printf("\n");
                        printf("+--------------------+\n");
                        printf("Loop application ENDED\n");
                        printf("+--------------------+\n");
                    }else{
                        printf("ERROR: To quit, the number of iterations should be 0!\n");
                    }
                    break;
            }
            
        }else
        {
            printf("ERROR: Invalid entered value(s)!\n");
        }
        printf("\n");
    }while(!(character == 'Q' && times == 0));

    return 0;
}