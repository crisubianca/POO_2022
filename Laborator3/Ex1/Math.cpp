#include "Math.h"

int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

int Math::Add(double x, double y)
{
	return x + y;
}

int Math::Add(double x, double y, double z)
{
	return x + y + z;
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

int Math::Mul(double x, double y)
{
	return x * y;
}

int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}

int Math::Add(int count, ...)
{
	int i;
	int sum = 0;
	va_list x; //facem o var de tipul va_list
	va_start(x, count); // va_start primeste variabila si n, nr de elemente
	for (i = 0; i < count ; i++)
	{
		sum = sum + va_arg(x, int); // va_arg primeste var si tipul elementului
	}
	va_end(x); // va_end obligatoriu
	return sum;
}

char* Math::Add(const char* x , const char* y)
{
	if (x == nullptr || y == nullptr) return nullptr;
	int nr1 = 0, nr2 = 0;
	int i;
	for ( i = 0; i < strlen(x); i++)
	{
		nr1 = nr1 * 10 + x[i] - '0';
	}
	int j;
	for (j = 0; j < strlen(x); j++)
	{
		nr2 = nr2 * 10 + y[j] - '0';
	}
	char* sir = new char[256];
	nr2 = nr1 + nr2;
	_itoa(nr2, sir, 10);
	return sir;
}