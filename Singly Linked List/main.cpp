#include<iostream>

#include "singlylinkedlist.h"

using namespace std;

int main()
{
	SList<float> list;
	
	list.addFront(100);
	
	list.addFront(200);
	
	list.addFront(300);	
	
	list.removeFront();
	
	cout << "First Element : " << list.front() << endl;
	
	cout << "List is empty ? : " << list.empty() << endl;
	
	
	return 0;
}
