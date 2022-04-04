#include <iostream>
#include <stdio.h>
#include <string.h>
template<class T, int size>
class vector {
private:
	T* vec;
	int count;
	int memory;
public:
	vector(): count(0), memory(size), vec(new T[size]) {}
	vector(const vector& other)
	{
		*this = other;
	}
	void push(T value)
	{
		if (this->count >= this->memory)
		{
			this->memory = this->memory * 2;
			T* v = new T[memory];
			memcpy(v, vec, (memory / 2) * sizeof(T));
			delete[] this->vec;
			vec = new T[this->memory];
			memcpy(vec, v, memory * sizeof(T));
		}
		this->count++;
		vec[count - 1] = value;
	}
	int count()
	{
		return this->count;
	}
	T pop()
	{

	}
};