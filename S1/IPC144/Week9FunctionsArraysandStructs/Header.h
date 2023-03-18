#pragma once
// guard conditions to ensure that the header file is only
// included once

#ifndef HEADER_H
#define HEADER_H

#define MAX_PAYS 10

struct Person
{
    char name[31];
    int age;
};

struct Employee
{
    struct Person personInfo;
    int employeeID;
    int numPays;
    double pays[MAX_PAYS];
};

/*
 * Function to assign the name to an employee.
 * Note that the struct is passed by address for efficiency.
 * emp - employee to set name for
 * name - name to assign to employee
 */
void setName(struct Employee *emp, char name[]); // prototype

/*
 * Append a value onto the end of an array.
 * ar - aray to append onto
 * value - value to append
 * size - current size of array
 * Returns - new size of the array
 */
int addToArry(double ar[], double value, int size);

/**
 * Add a new pay onto the employee.
 * emp - employee to add pay
 * pay - pay to add
 */
void addPay(struct Employee *emp, double pay);

void printEmployee(const struct Employee *emp);

#endif