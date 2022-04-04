#pragma once
#include <stdio.h>
// Kelvin to Celsius
float operator"" _Kelvin(const char* K)
{
    int i = 0;
    float nr = 0;
    while (K[i] != '\0')
    {
        nr = nr * 10 + K[i] - 48;
        i++;
    }
    return nr - 273.15;
}
// Fahrenheit to Celsius
float operator"" _Fahrenheit(const char* F)
{
    int i = 0;
    float nr = 0;
    while (F[i] != '\0')
    {
        nr = nr * 10 + F[i] - 48;
        i++;
    }
    return (nr - 32) / 1.8;
}
