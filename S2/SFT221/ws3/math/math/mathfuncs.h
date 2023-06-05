#pragma once
#ifndef MATHFUNCS_H
#define MATHFUNCS_H

//double square(double n);
//double cube(double n);

struct enter {
	char firstName[11];
	char lastName[11];
	char streetAddress[21];
	char city[11];
	char province[11];
	char postalCode[8];
};


int getFirstName(char* firstName);
int getLastName(char* lastName);
int notEmpty(char* temp);
int getStreetAddress(char* streetAddress);
int getCity(char* city);
int getProvince(char* province);
int getPostalCode(char* postalCode);
int centerIsSpace(char* temp);
void clearInputBuffer(void);

#endif