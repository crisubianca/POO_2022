#pragma once
#include "Operatii.h"
class Adunare :public Operatii
{
public:
	int Calcul(int a, int b) override;
	int GetOperationType() override;
	const char* GetName();
};