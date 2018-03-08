#pragma once
#include <iostream>
using namespace std;
class Exception
{
	
public:
	Exception(){};
	Exception(const char* msg){
		cout << msg << endl;
	}
	~Exception(){}
};
class ExceptionMemory : public Exception
{
public:
	ExceptionMemory() : Exception(){};
	ExceptionMemory(const char* msg) : Exception(msg){};
	~ExceptionMemory(){}
};
class ExceptionUnderflow : public Exception
{
public:
	ExceptionUnderflow() : Exception(){};
	ExceptionUnderflow(const char* msg) : Exception(msg){};
	~ExceptionUnderflow(){}
};
class ExceptionOverflow : public Exception
{
public:
	ExceptionOverflow():Exception(){};
	ExceptionOverflow(const char* msg) : Exception(msg){};
	~ExceptionOverflow(){}
};

