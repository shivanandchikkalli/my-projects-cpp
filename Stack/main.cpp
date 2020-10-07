#include<iostream>

#include "stackheader.h"

using namespace std;


int main(int argc, char* argv[])
{
	Stack<string> stack;

	stack.push("a");
	stack.push("b");
	stack.push("c");
	stack.push("d");

	stack.pop();

	cout << "Top element on stack : " << stack.top() << endl;
	
	return 0;
}
