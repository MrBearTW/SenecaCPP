#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stringhelp.h"
#include <string.h>
#include <ctype.h>

int main(void)
{
    char testStr[] = {"This is a\n string with embedded newline characters and\n12345 numbers inside it as well 7890"};

    struct StringIndex index = indexString(testStr);

    int i;
    
    printf("LINES\n");
    for (i = 0; i < index.numLines; i++)
    {
        printUntil(index.str, index.lineStarts[i], '\n');
        printf("\n");
    }
    
    printf("\nWORDS\n");
    for (i = 0; i < index.numWords; i++)
    {
        printUntilSpace(index.str, index.wordStarts[i]);
        printf("\n");
    }
    
    printf("\nNUMBERS\n");
    for (i = 0; i < index.numNumbers; i++)
    {
        printUntilSpace(index.str, index.numberStarts[i]);
        printf("\n");
    }
    return 0;
}

// This is a\n
//  string with embedded newline characters and\n
// 12345 numbers inside it as well 7890

// struct StringIndex
// {
//     char str[MAX_STRING_SIZE + 1];
//     int wordStarts[MAX_INDEX_SIZE];
//     int lineStarts[MAX_INDEX_SIZE];
//     int numberStarts[MAX_INDEX_SIZE];
//     int numWords, numLines, numNumbers;
// };