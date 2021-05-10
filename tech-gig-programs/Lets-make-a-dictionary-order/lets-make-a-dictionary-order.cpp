/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<string> input = {};
	int count = 0;
	cin >> count;

	for(int i = 0 ; i < count+1 ; i++) 
	{
		string str = "";
		getline(cin, str);
		input.push_back(str);
	}

	std::sort(input.begin(), input.end());

	int counter = 0;
	for(string val : input){
		if(counter++ == 0)
			continue;
		else
			cout << val << endl;
	}
	
	return 0;
}