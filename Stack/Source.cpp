#include "Header.h"
#include <iostream>
using namespace std;
bool removeFromStack(StackInt& st1, int item){
	bool bo = true;
	StackInt st2;
	if (!st1.isEmpty()){
		int temp = st1.pop();
		while (temp != item && bo){
			if (!st1.isEmpty()){
				st2.push(temp);
				temp = st1.pop();
			}
			else bo = false;
		}
		if (bo) while (!st2.isEmpty())st1.push(st2.pop());
	}
	else
	{
		bo = false;
	}
	return bo;
}
int main(){
	try{
		StackInt stack1, stack2; 
		void shiftStack(char ch);
		char* str = new char[100];
		cin >> str;
		bool bo = true;
		for (int i = 0; str[i] != 0 && bo; i++){
			switch (str[i])
			{
			case '(':
					stack1.push('(');
					break;
			case '[':
					stack1.push('[');
					break;
			case '{':
					stack1.push('{');
					break;
			case ')':
				bo = removeFromStack(stack1, '(');
				break;
			case ']':
				bo = removeFromStack(stack1, '[');
				break;
			case '}':
				bo = removeFromStack(stack1, '{');
				break;
			}
		}
		bo = bo && stack1.isEmpty();
		cout << bo;
	}
	catch (Exception &exc){}
	system("pause");
	return 0;
}
