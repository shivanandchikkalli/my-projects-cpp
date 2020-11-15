#include <iostream>

#include "list.h"

using namespace std;

int main()
{
	NodeList asd;

	cout << "empty? : " << asd.empty() << "   Size : " << asd.size() << endl;

	asd.insertFront(100);
	asd.insertFront(200);
	asd.insertFront(300);
	asd.insertFront(400);

	cout << "empty? : " << asd.empty() << "   Size : " << asd.size() << endl;

	for(NodeList::Iterator i = asd.begin() ; i != asd.end() ; ++i)
	{
		cout << *i << " ";
	}

	asd.insertBack(100);
	asd.insertBack(200);
	asd.insertBack(300);
	asd.insertBack(400);

	cout << endl << "empty? : " << asd.empty() << "   Size : " << asd.size() << endl;

	for(NodeList::Iterator i = asd.begin() ; i != asd.end() ; ++i)
	{
		cout << *i << " ";
	}

	asd.removeFront();
	asd.removeBack();

	cout << endl << "empty? : " << asd.empty() << "   Size : " << asd.size() << endl;

	for(NodeList::Iterator i = asd.begin() ; i != asd.end() ; ++i)
	{
		cout << *i << " ";
	}



	return 0;
}
