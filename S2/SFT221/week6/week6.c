#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "log4c.h"

int main(void)
{
    char errMsg[L4C_ERROR_MSG_MAX + 1] = { 0 };
    struct Log4cStruct log = l4cOpen("log.txt", 0);
    if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);
    else
    {
        l4cError(&log, "error msg");
        if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);

        l4cWarning(&log, "warning msg");
        if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);

        l4cInfo(&log, "info msg");
        if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);

        l4cPrintf(&log, L4C_INFO, "I am %d years old", 47);
        if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);

        l4cClose(&log);
    }

    return 0;
}