#pragma once
#include "Operatii.h"
class Scadere :public Operatii
{
public:
	int Calcul(int a, int b) override;
	int GetOperationType() override;
	const char* GetName();
};
