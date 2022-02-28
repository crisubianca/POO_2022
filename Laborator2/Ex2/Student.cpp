#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Student.h"

void Student::SetName(char str[50])
{
	strcpy(Name, str);
}
char* Student::GetName()
{
	return Name;
}
void Student::SetGradeM(float value)
{
	if (value >= 1 && value <= 10)
		Mathematics = value;
}
void Student::SetGradeE(float value)
{
	if (value >= 1 && value <= 10)
		English = value;
}
void Student::SetGradeH(float value)
{
	if (value >= 1 && value <= 10)
		History = value;
}
float Student::GetGradeM()
{
	return Mathematics;
}
float Student::GetGradeE()
{
	return English;
}
float Student::GetGradeH()
{
	return History;
}
float Student::AverageGrade()
{
	return (Mathematics + English + History) / 3;
}