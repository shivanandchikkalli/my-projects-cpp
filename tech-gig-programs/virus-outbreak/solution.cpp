/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string virusName = "";
	int count = 0;
	vector<string> people = {};
	cin >> virusName;
	cin >> count;
	for(int i = 0 ; i < count ; i++)
	{
		string name = "";
		cin >> name;
		people.push_back(name);
	}
	//cout << virusName << endl;
	//cout << count << endl;
	for(string n : people)
	{
		//cout << n << endl;
		int nameIndex = 0;
		auto vPtr = virusName.begin();
		while(vPtr != virusName.end() && nameIndex < n.size()){
			if(n[nameIndex] == *vPtr)
				nameIndex++;
			vPtr++;
		}
		if(nameIndex == n.size())
			cout << "POSITIVE" << endl;
		else
			cout << "NEGATIVE" << endl;
	}
	
	//Write code here
}