/*
Organize the code in the following way:

-a header file called Math.h

-a cpp file called Math.cpp that contains the source code for class Math

-a main file called main.cpp that contains the main function and has an example on how to use Math. The example must include using all methods from the class.

-for the variadic method use pointers or va_start / va_end macros.

-Add(const char *, const char *) will allocate memory that can add the two existing string. If one of the strings is nullptr, this function will return nullptr;
*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
class Math
{
public:
    static int Add(int, int);
    static int Add(int, int, int);
    static int Add(double, double);
    static int Add(double, double, double);
    static int Mul(int, int);
    static int Mul(int, int, int);
    static int Mul(double, double);
    static int Mul(double, double, double);
    static int Add(int count, ...); // sums up a list of integers
    static char* Add(const char*, const char*);
};