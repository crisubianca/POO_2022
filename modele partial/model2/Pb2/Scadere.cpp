#include "Scadere.h"
int Scadere::Calcul(int a, int b)
{
	return (a - b);
}
int Scadere::GetOperationType()
{
	return 1;
}
const char* Scadere::GetName()
{
	return "Scadere";
}