#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"

int main(void)
{
    struct Employee emp1 = {{{"Billy Bob"}, 45}, 123, 2, {46.5, 87.23}};

    printf("Employee %d: %s\n", emp1.employeeID, emp1.personInfo.name);

    setName(&emp1, "Selly Sue");

    printf("Employee %d: %s\n", emp1.employeeID, emp1.personInfo.name);

    addPay(&emp1, 99.99);
    printEmployee(&emp1);
    printf("/n");

    return 0;
}

// this IDE has not compiled header.h and w9class.c together and seems to think they are in separate projects