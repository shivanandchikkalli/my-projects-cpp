#include <iostream>

#include "generic-list.h"

using namespace std;

int main()
{
	NodeList<char> asd;

	cout << "empty? : " << asd.empty() << "   Size : " << asd.size() << endl;

	asd.insertFront('a');
	asd.insertFront('b');
	asd.insertFront('c');
	asd.insertFront('d');

	cout << "empty? : " << asd.empty() << "   Size : " << asd.size() << endl;

	for(NodeList<char>::Iterator i = asd.begin() ; i != asd.end() ; ++i)
	{
		cout << *i << " ";
	}

	asd.insertBack('a');
	asd.insertBack('b');
	asd.insertBack('c');
	asd.insertBack('d');

	cout << endl << "empty? : " << asd.empty() << "   Size : " << asd.size() << endl;

	for(NodeList<char>::Iterator i = asd.begin() ; i != asd.end() ; ++i)
	{
		cout << *i << " ";
	}

	asd.removeFront();
	asd.removeBack();

	cout << endl << "empty? : " << asd.empty() << "   Size : " << asd.size() << endl;

	for(NodeList<char>::Iterator i = asd.begin() ; i != asd.end() ; ++i)
	{
		cout << *i << " ";
	}



	return 0;
}
