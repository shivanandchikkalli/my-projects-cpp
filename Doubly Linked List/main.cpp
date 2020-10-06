#include<iostream>
#include<string.h>

#include "doublylinkedlist.h"

using namespace std;

template <typename T>
void print_list(const T& t)
{
	cout << "Item = " << t << endl;
}

int main(int argc, char** argv)
{
	DList<string> list;
	
	list.register_print_function(print_list);  // registering the print function with the list
	
	list.addFront("a");
	
	list.addFront("b");
	
	list.addFront("c");	
	
	list.print_list_items();
	
	return 0;
}
