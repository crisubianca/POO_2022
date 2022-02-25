/*Read a sentence from the input using scanf API.
Then sort split it into words and write to the screen
(using the printf API) the words sorted (from the 
longest one to the shortest one).If two words have
the same length - they will be sorted out alphabetically.
We consider that each word is separated from another one using space (one or multiple).

Example: let's consider the following sentence: 
"I went to the library yesterday". 
The program will print the following to the screen:
   			 yesterday
   			 library
   			 went
   			 the
   			 to
   			 I
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
int main()
{
    char sentence[100], str[20][100];
    printf("Write a sentence: ");
    scanf("%[^\n]s", &sentence);
    char* p;

    p = strtok(sentence, " ");
    int aux = 0;
    while (p != NULL)
    {
        strcpy(str[aux], p);
        aux++;
        printf("%s %d\n", p, strlen(p));
        p = strtok(NULL, " ");
    }
    for (int i = 0; i < aux - 1; i++)
    {
        for (int j = i; j < aux; j++)
        {
            if (strlen(str[i]) < strlen(str[j]))
            {
                char str_aux[30];
                strcpy(str_aux, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], str_aux);
            }
            else
            {
                if (strlen(str[i]) == strlen(str[j]))
                {
                    int length = strlen(str[i]);
                    for (int k = 0; k < length; k++)
                    {
                        if (str[i][k] < str[j][k])
                        {
                            char str_aux[30];
                            strcpy(str_aux, str[i]);
                            strcpy(str[i], str[j]);
                            strcpy(str[j], str_aux);
                            k = length + 1;
                        }
                        else
                        {
                            if (str[i][k] > str[j][k])
                            {
                                k = length + 1;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < aux; i++)
    {
        printf("%s\n", str[i]);
    }
}