#include "Functions.h"
#include "Student.h"
short CompareNames(Student n1, Student n2)
{
	int i = 0;
	char* str1 = n1.GetName();
	char* str2 = n2.GetName();
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] < str2[i])
			return -1;
		if (str1[i] > str2[i])
			return 1;
		i++;
	}
	if (str1[i] == str2[i])
		return 0;
	if (str1[i] == '\0')
		return -1;
	else
		return 1;
}
short CompareGradeM(Student n1, Student n2)
{
	if (n1.GetGradeM() < n2.GetGradeM())
		return -1;
	if (n1.GetGradeM() > n2.GetGradeM())
		return 1;
	return 0;
}
short CompareGradeE(Student n1, Student n2)
{
	if (n1.GetGradeE() < n2.GetGradeE())
		return -1;
	if (n1.GetGradeE() > n2.GetGradeE())
		return 1;
	return 0;
}
short CompareGradeH(Student n1, Student n2)
{
	if (n1.GetGradeH() < n2.GetGradeH())
		return -1;
	if (n1.GetGradeH() > n2.GetGradeH())
		return 1;
	return 0;
}
short CompareAverage(Student n1, Student n2)
{
	if (n1.AverageGrade() < n2.AverageGrade())
		return -1;
	if (n1.AverageGrade() > n2.AverageGrade())
		return 1;
	return 0;
}