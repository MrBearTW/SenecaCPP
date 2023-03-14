#pragma once
// guard conditions to ensure that the header file is only
// included once

#ifndef HEADER_H
#define HEADER_H

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
    double pays[10];
};

void setName(struct Employee *emp, char name[]); // prototype

int addToArry(double ar[], double value, int size);

void addPay(struct Employee *emp, double pay);

void printEmployee(const struct Employee *emp);

#endif