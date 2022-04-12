#pragma once

class Student
{
	char* name;
	char** materie;
	int* note;
	int length;

public:
	Student();
	Student(const char* name);
	const char* GetName();
	void operator=(int value);
	operator float();
	int& operator[](const char* materie);
	void PrintNote();

	~Student();
};