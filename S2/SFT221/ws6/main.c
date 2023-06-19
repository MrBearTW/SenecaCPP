/*
SFT221 – Workshop 6
Learning Outcomes
• Learn to use a logger to debug code,
• Learn to use assertions to aid in debugging,
• Learn debugging techniques.
Instructions
It just gets worse and worse. We let a junior developer work on the code you just fixed and it is broken again! This time, we want you to use a log file and assertions to find the bugs and fix them. DO NOT use the debugger as we want you to compare using log files and assertions to using the debugger. Take notes as to which debugging tools you use as there will be questions about which ones you used to find each bug later.
You should use the log4c library that was discussed in class and add log statements to the code to help you debug the code. You should also insert assertions to detect impossible situations and situations that indicate that something is wrong with the code. These assertions should be spread across all the stringhelp functions to detect possible errors, even after debugging is complete. You should consider that the assertions are being added for the long-term life of the program, not just for this debugging session. With luck, the assertions you add today will detect bugs introduced by other junior developers.
*/

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

/*
A Reflection, Research and Assessment
Reflections should consider the questions in depth and not be trivial. Some reflections might require research to properly answer the question. As a rough guideline, the answer to each reflection questions should be about 100 words in length.
1. Did you find more bugs using the log file or assertions? Why did one work better than the other?
2. Do you like to debug using log files or the debugger? Why do you prefer one over the other? Can you envision a situation where you would only be able to use log files? Would you be able to debug as well? Would you be able to debug at the same speed as using a debugger, slower or faster?
3. How did you gain confidence that you had found all the bugs? Would you bet your life savings that you found all the bugs? If not, what would you do so that you would feel comfortable betting that you had found all the bugs?
*/