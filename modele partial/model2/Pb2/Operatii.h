#pragma once
class Operatii
{
public:
	virtual int Calcul(int a, int b) = 0;
	virtual int GetOperationType() = 0;
	virtual const char* GetName() = 0;
};
