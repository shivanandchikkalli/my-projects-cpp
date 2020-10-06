#include<iostream>

#include "circularlinkedlist.h"

using namespace std;


int main(int argc, char** argv)
{
	CList<int> list;
	
	list.add(100);
	list.add(200);
	list.add(300);
	list.add(400);
	list.add(500);			
	
	cout << "Front : " << list.front() << endl;
	cout << "Back : " << list.back() << endl;
	
	list.remove();
	
	cout << "Front : " << list.front() << endl;
	cout << "Back : " << list.back() << endl;
	
	return 0;
}
