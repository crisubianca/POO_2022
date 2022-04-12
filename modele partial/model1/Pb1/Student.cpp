#include "Student.h"
#include <cstring>
#include <iostream>
Student::Student()
{
	length = 0;
	materie = new char* [20];
	note = new int[20];
	name = new char[20];
}
Student::Student(const char* n) :Student()
{
	int i = 0;
	while (n[i])
	{
		this->name[i] = n[i];
		i++;
	}
	this->name[i] = '\0';
}
const char* Student::GetName()
{
	return this->name;
}
int& Student::operator[](const char* m)
{
	//materie[length] = m;
	materie[length] = new char[20];
	int i = 0;
	while (m[i])
	{
		materie[length][i] = m[i];
		i++;
	}
	materie[length][i] = '\0';
	return note[length++];
}
void Student::operator=(int value)
{
	this->note[length] = value;
}
Student::operator float()
{
	float ma = 0;
	for (int i = 0; i < length; i++)
		ma += note[i];
	return ma / length;
}

void Student::PrintNote()
{
	for (int i = 0; i < length; i++)
		std::cout << materie[i] << "=>" << note[i] << std::endl;
}
Student::~Student()
{
	delete[]note;
	delete[]materie;
}