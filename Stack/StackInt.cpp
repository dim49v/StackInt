#include "StackInt.h"

StackInt::StackInt(){
	top = new int[maxSize + 1];
	if (top == 0){
		throw ExceptionMemory("Error. Memory not allocated");
	}
	arr = top;
}
bool StackInt::isEmpty() const{
	return(size == 0);
}
int StackInt::freePlace() const{
	return(maxSize - size);
}
void StackInt::push(int item){
	try{
		if (freePlace() > 0){
			top++;
			*top = item;
			size++;
		}
		else
		{
			throw ExceptionOverflow();
		}
	}
	catch (ExceptionOverflow& err){
		resize(100);
		push(item);
	}
}
int StackInt::pop(){
	if (isEmpty()){
		throw ExceptionUnderflow("Error. Stack is empty");
	}
	top--;
	size--;
	return *(top + 1);
}
void StackInt::resize(int addSize){
	maxSize += addSize;
	addSize = size;
	int* temp = new int[maxSize];
	if (temp == 0){
		throw ExceptionOverflow("Error. Place ended, to expand not managed");
	}
	for (int i = size - 1; i >= 0; i--){
		temp[i] = pop();
	}
 	delete[] top;
	top = temp;
	arr = top;
	size = addSize;
	top += size - 1;
	cout << "The place ended and was expanded to " << maxSize << endl;
}
StackInt::~StackInt()
{
	delete[] arr;
}
