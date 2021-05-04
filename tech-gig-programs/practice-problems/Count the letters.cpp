#include <iostream>
#include<string>
using namespace std;
int main()
{
	string input = "";

	getline(cin, input);

	int lowerCaseLetters = 0;
	int upperCaseLetters = 0;

	for(char chara : input)
	{
		if((int)chara <= 90 && (int)chara >= 65)
			upperCaseLetters++;
		if((int)chara >= 97 && (int)chara <= 122)
			lowerCaseLetters++;			
	}

	cout << upperCaseLetters << endl;
	cout << lowerCaseLetters << endl;
	
	return 0;
}