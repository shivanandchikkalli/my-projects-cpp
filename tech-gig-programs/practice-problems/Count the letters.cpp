/*Enter your code here. Read input from STDIN. Print your output to STDOUT

Count the letters
For this challenge, you need to take a string as an input from the stdin, count the number of uppercase and lowercase letters and print them to the stdout.

Input Format
A single line of string to be taken as an input and store it in a variable of your choice. 

Constraints
1 < = |s| < = 100000 

Output Format
print the number of uppercase letters on one line and number of lowercase letters on another side. 


*/
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