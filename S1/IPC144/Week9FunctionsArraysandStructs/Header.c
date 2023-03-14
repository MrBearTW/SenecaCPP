#include "Header.h" // "" --> searching folder

void setName(struct Employee *emp, char name[])
{
    int i;

    for (i = 0; name[i] != '\0'; i++)
    {
        (*emp).personInfo.name[i] = name[i];
    }

    emp->personInfo.name[i] = '\0'; // shortcut to acess struct member
/*
    int addToArry(double ar[], double value, int size)
    {
        ar[size] = value;
        return size + 1;
    }

    void addPay(struct Employee * emp, double pay)
    {
        // emp->pays[emp->numPays++] = pay;
        emp->numPays = addToArry(emp->pays, pay, emp->numPays);
    }
    
        void printEmployee(const struct Employee *emp)
        {
            int i;
            print("%s (%d): ", emp->personInfo.name, emp->employeeID);

            for (i = 0; i < emp->numPays; i++)
            {
                printf("%.2f", emp->)
            }
            }*/
}