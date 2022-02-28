#pragma once
class Student
{
	char Name[50];
	float Mathematics, English, History;
public:
	void SetName(char str[50]);
	char* GetName();
	void SetGradeM(float value);
	void SetGradeE(float value);
	void SetGradeH(float value);
	float GetGradeM();
	float GetGradeE();
	float GetGradeH();
	float AverageGrade();
};
