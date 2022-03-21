#include "Number.h"
Number::Number(const char* value, int base)
{
	Base = base;
	DigitsCount = strlen(value);
	number = new char[256];
	strcpy(number, value);
}
Number::Number(int value)
{
	Base = 10;
	number = new char[256];
	_itoa(value, number, 10);
}
Number::~Number()
{
	if (number != nullptr)
	{
		delete[] number;
	}
}
void Number::Print()
{
	printf("%s\n", number);
}
int Number::GetBase()
{
	return Base;
}
int Number::GetDigitsCount()
{
	return DigitsCount;
}
char* Number::GetNumber()
{
	return this->number;
}
Number::Number(const Number&& n)
{
	//delete[] number;
	this->number = new char[256];
	strcpy(this->number, n.number);
	this->Base = n.Base;
	this->DigitsCount = n.DigitsCount;
}
Number::Number(const Number& n)
{
	this->number = new char[256];
	strcpy(this->number, n.number);
	this->Base = n.Base;
	this->DigitsCount = n.DigitsCount;
}
// Operators:
Number& Number::operator = (const Number&& other)
{
	if (this != &other)
	{
		delete[] this->number;
		this->number = new char[256];
		strcpy(this->number, other.number);
		this->Base = other.Base;
	}
	return *this;
}
Number& Number::operator = (const char* sir)
{
	Base = 10;
	strcpy(number, sir);
	return *this;
}
Number& Number::operator = (const int nr)
{
	Base = 2;
	_itoa(nr, number, 2);
	DigitsCount = strlen(number);
	return *this;
}
char Number::operator [](int value)
{
	return number[value];
}
bool Number::operator > (Number& n2)
{
	Number temp1 = *this, temp2 = n2;
	temp1.SwitchBase(10);
	temp2.SwitchBase(10);
	char* sir1 = temp1.GetNumber();
	char* sir2 = temp2.GetNumber();
	if (strlen(sir1) > strlen(sir2))
		return true;
	if (strlen(sir1) == strlen(sir2))
	{
		for (int i = 0; i < strlen(sir1); i++)
		{
			if ((int)sir1[i] < (int)sir2[i])
				return false;
			if ((int)sir1[i] > (int)sir2[i])
				return true;
		}
		return false;
	}
	return false;
}
bool Number::operator < (Number& n2)
{
	Number temp1 = *this, temp2 = n2;
	temp1.SwitchBase(10);
	temp2.SwitchBase(10);
	char* sir1 = temp1.GetNumber();
	char* sir2 = temp2.GetNumber();
	if (strlen(sir1) < strlen(sir2))
		return true;
	if (strlen(sir1) == strlen(sir2))
	{
		for (int i = 0; i < strlen(sir1); i++)
		{
			if ((int)sir1[i] > (int)sir2[i])
				return false;
			if ((int)sir1[i] < (int)sir2[i])
				return true;
		}
		return false;
	}
	return true;
}
bool Number::operator >= (Number& n2)
{
	return (*this > n2 || *this == n2);
}
bool Number::operator <= (Number& n2)
{
	return (*this < n2 || *this == n2);
}
bool Number::operator == (Number& n2)
{
	Number temp1 = *this, temp2 = n2;
	temp1.SwitchBase(10);
	temp2.SwitchBase(10);
	char* sir1 = temp1.GetNumber();
	char* sir2 = temp2.GetNumber();
	if (strlen(sir1) == strlen(sir2))
	{
		for (int i = 0; i < strlen(sir1); i++)
		{
			if ((int)sir1[i] > (int)sir2[i])
				return false;
			if ((int)sir1[i] < (int)sir2[i])
				return false;
		}
		return true;
	}
	return false;
}
Number operator + (const Number& n1, const Number& n2)
{
	Number temp1 = n1, temp2 = n2;
	temp1.SwitchBase(10);
	temp2.SwitchBase(10);
	char* sir1 = temp1.GetNumber();
	char* sir2 = temp2.GetNumber();
	int sum = atoi(temp1.number) + atoi(temp2.number);
	if (n1.Base < n2.Base)
	{
		_itoa(sum, temp1.number, n2.Base);
		temp1.Base = n2.Base;
	}
	else
	{
		_itoa(sum, temp1.number, n1.Base);
		temp1.Base = n1.Base;
	}
	return temp1;
}
Number operator - (const Number& n1, const Number& n2)
{
	Number temp1 = n1, temp2 = n2;
	temp1.SwitchBase(10);
	temp2.SwitchBase(10);
	char* sir1 = temp1.GetNumber();
	char* sir2 = temp2.GetNumber();
	int sum = atoi(temp1.number) - atoi(temp2.number);
	if (n1.Base < n2.Base)
	{
		_itoa(sum, temp1.number, n2.Base);
		temp1.Base = n2.Base;
	}
	else
	{
		_itoa(sum, temp1.number, n1.Base);
		temp1.Base = n1.Base;
	}
	return temp1;
}
Number Number::operator +=(const Number& n2)
{
	*this = *this + n2;
	return *this;
}
Number Number::operator --()
{
	int i = strlen(number);
	for (int j = 0; j < i; j++)
	{
		number[j] = number[j + 1];
	}
	return *this;
}
Number Number::operator --(int value)
{
	int i = strlen(number);
	number[i - 1] = '\0';
	return *this;
}
void Number::SwitchBase(int newBase)
{
	if (newBase == this->Base || newBase <= 1 || newBase > 36)
	{
		//printf("Baza invalida sau bazele sunt egale!\n");
		return;
	}
	// Duc numarul in baza 10
	int i = strlen(this->number) - 1;
	int nr = 0;
	int tempnr = 1;
	while (i >= 0)
	{
		char s = this->number[i];
		int tempnr2;
		switch (s)
		{
		case 'a': tempnr2 = 10;
			break;
		case 'b': tempnr2 = 11;
			break;
		case 'c': tempnr2 = 12;
			break;
		case 'd': tempnr2 = 13;
			break;
		case 'e': tempnr2 = 14;
			break;
		case 'f': tempnr2 = 15;
			break;
		case 'g': tempnr2 = 16;
			break;
		case 'h': tempnr2 = 17;
			break;
		case 'i': tempnr2 = 18;
			break;
		case 'j': tempnr2 = 19;
			break;
		case 'k': tempnr2 = 20;
			break;
		case 'l': tempnr2 = 21;
			break;
		case 'm': tempnr2 = 22;
			break;
		case 'n': tempnr2 = 23;
			break;
		case 'o': tempnr2 = 24;
			break;
		case 'p': tempnr2 = 25;
			break;
		case 'q': tempnr2 = 26;
			break;
		case 'r': tempnr2 = 27;
			break;
		case 's': tempnr2 = 28;
			break;
		case 't': tempnr2 = 29;
			break;
		case 'u': tempnr2 = 30;
			break;
		case 'v': tempnr2 = 31;
			break;
		case 'w': tempnr2 = 32;
			break;
		case 'x': tempnr2 = 33;
			break;
		case 'y': tempnr2 = 34;
			break;
		case 'z': tempnr2 = 35;
			break;
		default: tempnr2 = s - 48;
		}
		nr = nr + tempnr * tempnr2;
		tempnr *= this->Base;
		i--;
	}

	if (newBase > this->Base)
	{
		//char* no = new char[strlen(this->number)];
		char* no = new char[256];
		_itoa(nr, no, 10);
		strcpy(this->number, no);
	}
	else
	{
		//char* no = new char[strlen(this->number) * 10];
		char* no = new char[256];
		_itoa(nr, no, 10);
		//delete[] this->number;
		//this->number = new char[strlen(no) * 2];
		strcpy(this->number, no);
	}
	if (newBase != 10)
	{
		if (newBase <= 9)
		{
			nr = 0;
			for (i = 0; i < strlen(this->number); i++)
			{
				nr = nr * 10 + this->number[i] - 48;
			}
			tempnr = 0;
			//char* no = new char[strlen(this->number) * 10];
			char* no = new char[256];
			i = 0;
			while (nr != 0)
			{
				tempnr = nr % newBase;
				nr = nr / newBase;
				i++;
				if (i == 1)
				{
					no[0] = tempnr + 48;
					no[1] = '\0';
				}
				else
				{
					int j = i;
					while (0 <= j - 1)
					{
						no[j] = no[j - 1];
						j--;
					}
					no[0] = tempnr + 48;
				}
			}
			//delete[] this->number;
			//this->number = new char[strlen(no) * 2];
			strcpy(this->number, no);
		}
		else
		{
			nr = 0;
			for (i = 0; i < strlen(this->number); i++)
			{
				nr = nr * 10 + this->number[i] - 48;
			}
			tempnr = 0;
			//char* no = new char[strlen(this->number)];
			char* no = new char[256];
			i = 0;
			while (nr != 0)
			{
				tempnr = nr % newBase;
				nr = nr / newBase;
				i++;
				char s;
				switch (tempnr)
				{
				case 10: s = 'a';
					break;
				case 11: s = 'b';
					break;
				case 12: s = 'c';
					break;
				case 13: s = 'd';
					break;
				case 14: s = 'e';
					break;
				case 15: s = 'f';
					break;
				case 16: s = 'g';
					break;
				case 17: s = 'h';
					break;
				case 18: s = 'i';
					break;
				case 19: s = 'j';
					break;
				case 20: s = 'k';
					break;
				case 21: s = 'l';
					break;
				case 22: s = 'm';
					break;
				case 23: s = 'n';
					break;
				case 24: s = 'o';
					break;
				case 25: s = 'p';
					break;
				case 26: s = 'q';
					break;
				case 27: s = 'r';
					break;
				case 28: s = 's';
					break;
				case 29: s = 't';
					break;
				case 30: s = 'u';
					break;
				case 31: s = 'v';
					break;
				case 32: s = 'w';
					break;
				case 33: s = 'x';
					break;
				case 34: s = 'y';
					break;
				case 35: s = 'z';
					break;
				default: s = tempnr + 48;
				}
				if (i == 1)
				{
					no[0] = s;
					no[1] = '\0';
				}
				else
				{
					int j = i;
					while (0 <= j - 1)
					{
						no[j] = no[j - 1];
						j--;
					}
					no[0] = s;
				}
			}
			strcpy(this->number, no);
		}
	}
	if (this->Base == 10)
	{
		if (newBase <= 9)
		{
			int nr = 0;
			int i;
			for (i = 0; i < strlen(this->number); i++)
			{
				nr = nr * 10 + this->number[i] - 48;
			}
			int b = 0;
			//char* no = new char[strlen(this->number) * 10];
			char* no = new char[256];
			i = 0;
			while (nr != 0)
			{
				b = nr % newBase;
				nr = nr / newBase;
				i++;
				if (i == 1)
				{
					no[0] = b + 48;
					no[1] = '\0';
				}
				else
				{
					int j = i;
					while (0 <= j - 1)
					{
						no[j] = no[j - 1];
						j--;
					}
					no[0] = b + 48;
				}
			}
			//delete[] this->number;
			//this->number = new char[strlen(no) * 2];
			strcpy(this->number, no);
		}
		else
		{
			int nr = 0;
			int i;
			for (i = 0; i < strlen(this->number); i++)
			{
				nr = nr * 10 + this->number[i] - 48;
			}
			int tempnr = 0;
			//char* no = new char[strlen(this->number)];
			char* no = new char[256];
			i = 0;
			while (nr != 0)
			{
				tempnr = nr % newBase;
				nr = nr / newBase;
				i++;
				char s;
				switch (tempnr)
				{
				case 10: s = 'a';
					break;
				case 11: s = 'b';
					break;
				case 12: s = 'c';
					break;
				case 13: s = 'd';
					break;
				case 14: s = 'e';
					break;
				case 15: s = 'f';
					break;
				case 16: s = 'g';
					break;
				case 17: s = 'h';
					break;
				case 18: s = 'i';
					break;
				case 19: s = 'j';
					break;
				case 20: s = 'k';
					break;
				case 21: s = 'l';
					break;
				case 22: s = 'm';
					break;
				case 23: s = 'n';
					break;
				case 24: s = 'o';
					break;
				case 25: s = 'p';
					break;
				case 26: s = 'q';
					break;
				case 27: s = 'r';
					break;
				case 28: s = 's';
					break;
				case 29: s = 't';
					break;
				case 30: s = 'u';
					break;
				case 31: s = 'v';
					break;
				case 32: s = 'w';
					break;
				case 33: s = 'x';
					break;
				case 34: s = 'y';
					break;
				case 35: s = 'z';
					break;
				default: s = tempnr + 48;
				}
				if (i == 1)
				{
					no[0] = s;
					no[1] = '\0';
				}
				else
				{
					int j = i;
					while (0 <= j - 1)
					{
						no[j] = no[j - 1];
						j--;
					}
					no[0] = s;
				}
			}
			strcpy(this->number, no);
		}
	}
	this->Base = newBase;
}