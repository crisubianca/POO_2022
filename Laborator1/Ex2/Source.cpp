/*Ex2.Write a program in C - Language that open the file "in.txt", and prints the sum of the numbers
that are found on each line of the file in.txt.To open the file use fopen API.Write your own
function that converts a string to a number(similar cu atoi API).To print something to the
screen, use the printf API.
Example: let's consider the following "ini.txt" file:
123
198698
5009
983279
The program will print to the screen 1187109.*/
#include <cstdio>
int atoi(char str[])
{
	int aux = 0;
	int position = 0;
	while (str[position] != NULL)
	{
		aux = aux * 10 + str[position] - '0';
		position++;
	}
	return aux;
}


int main()
{
	FILE *fisier;
	errno_t err;
	err = fopen_s(&fisier, "Text.txt", "r");
	if (err == 0)
	{
		printf("The file was opened\n");
	}
	else
	{
		printf("The file was not opened\n");
	}
	int sum = 0;
	char str[50]; int nr;
	while (!feof(fisier))
	{
		fscanf_s(fisier, "%s", str, sizeof(str));
		nr = atoi(str);
		printf("Nr is: %d \n", nr);
		sum += nr;
	}
	printf("The sum it's %d. \n", sum);
	if (fisier)
	{
		err = fclose(fisier);
		if (err == 0)
		{
			printf("The file was closed\n");
		}
		else
		{
			printf("The file was not closed\n");
		}
	}
}