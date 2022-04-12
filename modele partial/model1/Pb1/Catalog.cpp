#include "Catalog.h"
#include <iostream>
#include <cstring>
Catalog::Catalog()
{
	count = 0;
}
void Catalog::operator +=(const char* name_student)
{
	student[count++] = Student(name_student);
}
Student& Catalog::operator [](const char* name)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(student[i].GetName(), name) == 0)
		{
			return student[i];
		}
	}
}
Student& Catalog::operator [](int index)
{
	//if(index<0 || index>count)

	return student[index];
}
int Catalog::GetCount()
{
	return count;
}
void Catalog::Print()
{
	for (int i = 0; i < count; i++)
		std::cout << student[i].GetName() << std::endl;
}