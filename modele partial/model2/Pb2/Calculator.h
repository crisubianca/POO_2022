#pragma once
#include "Operatii.h"
class Calculator
{
	Operatii* operatie[4];
	int numberOp;
public:
	Calculator();
	Calculator& operator +=(Operatii* op);
	operator int();
	bool operator[] (const char* name);
	void operator -=(const char* name);
	void Compute(int a, int b);

};