#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
class Number
{
	// data members
	char* number;
	int Base;
	int DigitsCount;

public:
	Number(const char* value, int base); // base is between 2 and 36
	Number(int value);
	~Number();
	// add the following operators: addition, subtraction, negate, index operator, relation operators (> , < , >= , <=, ==, etc)
	// copy/move constructors 
	Number(const Number& n); // Copy
	Number(const Number&& n); // Move

	// Operators:
	Number& operator = (const Number&& other); // move assignment operator

	friend Number operator + (const Number& n1, const Number& n2);
	friend Number operator - (const Number& n1, const Number& n2);

	Number& operator = (const char* sir);
	Number& operator = (const int nr);

	bool operator > (Number& n2);
	bool operator < (Number& n2);
	bool operator == (Number& n2);
	bool operator >= (Number& n2);
	bool operator <= (Number& n2);
	char operator [](int value);
	Number operator +=(const Number& n2);
	Number operator --(); // prefixata
	Number operator --(int value);  // postfixata
	void SwitchBase(int newBase);
	void Print();
	char* GetNumber();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};
