#include "Calculator.h"
#include <string.h>
#include <stdio.h>
//#include <initializer_list>
Calculator::Calculator()
{
	numberOp = 0;
	//Operatii* operatie[4] = {};
	for (int i = 0; i < 4; i++)
		operatie[i] = nullptr;
}
Calculator& Calculator::operator +=(Operatii* op)
{
	int index;
	index = op->GetOperationType();
	if (operatie[index] != nullptr)
	{
		return *this;
	}
	operatie[index] = op;// doar daca nu am introdus operatia inainte
	numberOp++;
	return *this;
}
Calculator::operator int()
{
	return numberOp;
}
bool Calculator::operator [](const char* name)
{
	for (int i = 0; i < 4; i++)
	{
		if (operatie[i] != nullptr && strcmp(operatie[i]->GetName(), name) == 0)
		{
			return 1;
		}
	}
	return 0;
}
void Calculator::operator -=(const char* name)
{
	int index = -1;
	for (int i = 0; i < 4; i++)
	{
		if (operatie[i] != nullptr && strcmp(operatie[i]->GetName(), name) == 0)
		{
			index = i;
			break;
		}
	}
	operatie[index] = nullptr;
}
void Calculator::Compute(int a, int b)
{
	for (int i = 0; i < 4; i++)
	{
		if (!operatie[i])
			continue;
		printf("%s(%d,%d)=%d\n", operatie[i]->GetName(), a, b, operatie[i]->Calcul(a, b));
	}
}