#include <iostream>

#include "vector.h"
#include "vector.cpp"

using namespace std;

int main() {

	Vector<int> intVector;

	cout << "Vector empty? : " << intVector.empty() << endl;

	intVector.push_back(100);
	intVector.push_back(200);
	intVector.push_back(300);
	intVector.push_back(400);
	intVector.push_back(500);
	intVector.push_back(600);

	cout << "Vector empty? : " << intVector.empty() << endl;

	cout << "Vector front() element : " << intVector.front() << endl;
	cout << "Vector back() element : " << intVector.back() << endl;

	cout << endl << "Elements At Vector " << endl;

	for(int i = 0; i < intVector.size(); i++)
	{
		cout << "Vector back() element : " << intVector.at(i) << endl;
	}

	intVector.pop_back();
	intVector.pop_back();

	cout << endl << "Elements At Vector " << endl;

	for(int i = 0; i < intVector.size(); i++)
	{
		cout << "Vector back() element : " << intVector[i] << endl;
	}

	return 0;
}
