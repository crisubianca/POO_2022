#include <stdio.h>
#include "NumberList.h"
void NumberList::Init()
{
    count = 0;
}
bool NumberList::Add(int x)
{
    if (count >= 10)
        return false;
    numbers[count] = x;
    count++;
}
void NumberList::Sort()
{
    for (int i = 0; i < count - 1; i++)
        for (int j = i; j < count; j++)
            if (numbers[i] > numbers[j])
            {
                int aux = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = aux;
            }
}
void NumberList::Print()
{
    printf("Lista este: ");
    for (int i = 0; i < count; i++)
        printf(" %d", numbers[i]);
    printf("\n");
}