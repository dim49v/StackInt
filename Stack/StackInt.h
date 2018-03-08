#pragma once
#include "Exception.h"
class StackInt
{
private:
	int maxSize = 100;
	int size;
	int* top;
	int* arr;
	void resize(int addSize);
public:
	StackInt();
	bool isEmpty() const;
	int freePlace() const;
	void push(int item);
	int pop();
	~StackInt();
};

