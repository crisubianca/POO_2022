#include "Math.h"

void main()
{
	Math m;
	printf("Adunari: %d %d %d %d %d %s \n", m.Add(6, 5), m.Add(3, 5, 7), m.Add(3.5, 6.7), m.Add(7.3, 4.5, 8.5), m.Add(6, 3, 4, 5, 34, 45, '0'), m.Add("123", "167"));
	printf("Inmultiri: %d %d %d %d", m.Mul(5, 5), m.Mul(5, 5, 4), m.Mul(5.2, 5.5), m.Mul(10.5, 5.3, 8.4));
}