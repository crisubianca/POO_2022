#pragma once
#include "Student.h"
class Catalog
{
	Student student[20];
	int count;
public:
	Catalog();
	void operator +=(const char* name_student);
	Student& operator [](const char* n);
	Student& operator [](int index);
	void Print();
	int GetCount();
};
