#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    if(1 == 0) printf("1 is 1\n");
    else
    {   // this is a code block which can be used anywhere a stmt is use
        printf("1 is not 1, we are in trouble\n");
    }
        
    int age = 0;
    printf("How old are you? ");
    scanf("%d", &age);

    if (age<12)
    {
        printf("Just a youngster\n");
    }
    else
    {
        if (age<20) // nestedn if
        {
            printf("The teens are the best time of life\n");
        }
        else if (age<65)
        {
            printf("adults make all the money\n");
        }
        else printf("Seniors should ask for the senior disscounts\n");

    }
    
    int color = 0;
    printf("What is your favourite color?\n");
    printf("1-red\n");
    printf("2-green\n");
    printf("3-blue\n");
    printf("4-yellow\n");
    printf("5-brown\n");
    printf("6-purple\n");
    scanf("%d", &color);

    if(color == 1)
    {
        printf("Red is a happy color\n");
    }
    else
    {
        if (color ==2)
        {
            printf("green is the color of nature\n");
        }
        else if (color == 3)
        {
            printf("blue is the mostpopulor color\n");
        }
    }
    
    // this is a better way of doing different things based on the value of a single variable
    
    if(1 == 1)
        printf("1 is still 1 \n");
    printf("1 is not 2\n");     // this is outside the if
    
    int fruit = 0;
    printf("Which do you prefer?\n");
    printf("1-apples\n");
    printf("2-orange\n");
    printf("3-pears\n");
    scanf("%d", &fruit);
    
    switch(fruit)
    {
        case 1:
            printf("An apple a\n");
            break;
        case 2:
            printf("orange\n");
            break;
        case 3:
            printf("pears are grown in Ontario\n");
            break;
        default:        // matches a value not matched above
            printf("This is not a valid selection\n");
    }
    
    char yesNo = ' ';
    printf("Would you like a coffee?(y/n) ");
    scanf(" %c%*c", &yesNo);     // one get the char and throw the  /n away
    
    switch(yesNo)
    {
        case 'Y':
        case 'y':
            printf("hot coffee on the way\n");
            break;
        case 'N':
        case 'n':
            printf("maybe tea is better??\n");
            break;
        default:
            printf("I cannot understand anything you say\n");
    }
    
    printf("What is your age? ");
    scanf("%d%*c", &age);
    printf("Do you like movies? ");
    scanf("%c", &yesNo);

    if(age<18 && (yesNo =='y' || yesNo=='Y'))
    {
        printf("Many teans like movies, just like you\n");
    }
    else if( age < 18 && (yesNo =='n' || yesNo=='N'))
    {
        printf("movie hating teens are rare\n");
    }
    
    int n;
    int evenCount = 0;
    printf("Type a number: ");
    scanf("%d", &n);
    printf("That number is %s\n", ((n %2) ==0) ? "even" : "odd");
                               // (!(n %2) ? "even" : "odd")
    
    evenCount += ((n % 2) == 0)? 1 : 0;
    printf("Type a number: ");
    scanf("%d", &n);
    evenCount += ((n % 2) == 0)? 1 : 0;
    
    printf("You entered %d even numbers\n", evenCount);
    
    int disscountPercent = 0;
    printf("What is your age? ");
    scanf("%d%*c", &age);
    // ye olde nested
    disscountPercent = (age < 12) ? 100: ((age >= 65) ? 25 : 0);
     
    printf("%d\n", disscountPercent);
         
    
           
    return 0;
}