#include <iostream>
#include <stdio.h>
#include <string.h>
template<class T, int size>
class vector
{
private:
	T* vec;
	int countt;
	int memory;
public:
	vector() : countt(0), memory(size), vec(new T[size]) {}
	vector(const vector& other)
	{
		*this = other;
	}
	void push(T value)
	{
		if (this->countt >= this->memory)
		{
			this->memory = this->memory * 2;
			T* v = new T[memory];
			memcpy(v, vec, (memory / 2) * sizeof(T));
			delete[] this->vec;
			vec = new T[this->memory];
			memcpy(vec, v, memory * sizeof(T));
		}
		this->countt++;
		vec[countt - 1] = value;
	}
	int count()
	{
		return this->countt;
	}
	T pop()
	{
		this->countt--;
		return this->vec[this->countt];
		vec[countt + 1] = 0;
	}
	void remove(int index)
	{
		for (int i = index; i < this->countt; i++)
			vec[i] = vec[i + 1];
		this->countt--;
	}
	void insert(int index, T element)
	{
		if (this->countt >= this->memory)
		{
			this->memory = this->memory * 2;
			T* v = new T[memory];
			memcpy(v, vec, (memory / 2) * sizeof(T));
			delete[] this->vec;
			vec = new T[this->memory];
			memcpy(vec, v, memory * sizeof(T));
		}
		this->countt++;
		for (int i = this->countt - 1; i > index; i--)
			vec[i + 1] = vec[i];
		vec[index] = element;
	}
	const T& get(int index)
	{
		return this->vec[index];
	}
	void set(int index, T element)
	{
		if (index < countt)
			vec[index] = element;
	}
	void sort(T(*Sortcallback)(T n1, T n2) = nullptr)
	{
		if ((*Sortcallback) != nullptr)
		{
			for (int i = 0; i < this->countt; i++)
				vec[i] = Sortcallback(vec[i], vec[i + 1]);
		}
		else
		{
			for (int i = 0; i < this->countt - 1; i++)
				for (int j = i + 1; j < this->countt; j++)
				{
					if (vec[i] < vec[j])
					{
						T aux = vec[i];
						vec[i] = vec[j];
						vec[j] = aux;
					}
				}
		}
	}
	void Print()
	{
		for (int i = 0; i < this->countt; i++)
			std::cout << "Element " << i << " is " << vec[i] << '\n';
	}
	int firstIndexOf(T parameter, bool (*Testcallback)(T n1, T n2) = nullptr)
	{
		if ((*Testcallback) != nullptr)
		{
			for (int i = 0; i < this->countt; i++)
				if (Testcallback(vec[i], parameter))
					return i;
		}
		else
		{
			for (int i = 0; i < this->countt; i++)
				if (vec[i] == parameter)
					return i;
		}
	}
};
bool TestIndex(int n1, int n2)
{
	if (n1 == n2 * 2)
		return true;
	return false;
}

int Test(int n1, int n2)
{
	if (n1 > n2)
		return n1;
}

int main()
{
	vector<int, 50> myvector;
	for (int i = 0; i <= 50; i++)
		myvector.insert(i, i);
	myvector.remove(4);
	myvector.push(10);
	myvector.push(30);
	myvector.push(50);
	myvector.set(8, 342);
	int nr = myvector.get(0);
	printf("%d\n", nr);
	myvector.Print();
	nr = myvector.pop();
	nr = myvector.pop();
	printf("%d\n", nr);
	myvector.sort();
	myvector.Print();
	nr = myvector.firstIndexOf(20, TestIndex);
	printf("%d\n", nr);
}