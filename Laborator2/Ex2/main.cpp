#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
#include "Student.h"
#include "Functions.h"

void main()
{
	Student S1, S2;
	char name[50] = "Mihai";
	S1.SetName(name);
	char* name1 = S1.GetName();
	float M = 9, E = 6, H = 6.5f, Average = 0, M1, E1, H1;
	S1.SetGradeM(M);
	S1.SetGradeE(E);
	S1.SetGradeH(H);
	M1 = S1.GetGradeM();
	E1 = S1.GetGradeE();
	H1 = S1.GetGradeH();
	Average = S1.AverageGrade();

	S2.SetGradeM(8);
	S2.SetGradeE(6);
	S2.SetGradeH(7);
	char name2[] = "Alex";
	S2.SetName(name2);

	printf("Student: %s. Grades: %f, %f, %f Average grade: %f \n", name1, M1, E1, H1, Average);
	printf("Student: %s. Grades: %f, %f, %f Average grade: %f \n", S2.GetName(), S2.GetGradeM(), S2.GetGradeE(), S2.GetGradeH(), S2.AverageGrade());
	printf("Compare names S1-S2: %d \nCompare grades S1-S2  M: %d E: %d H: %d Average: %d \n", CompareNames(S1, S2), CompareGradeM(S1, S2), CompareGradeE(S1, S2), CompareGradeH(S1, S2), CompareAverage(S1, S2));
}