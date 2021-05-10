/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include<vector>
using namespace std;
int main()
{
	int size = 0;
	cin >> size;

	vector<int> input(size, 0);

	for(int i = 0 ; i < size ; i++) {
		int num = 0;
		cin >> num;
		input.at(i) = num;
	}

	int minIndex = 0;
	for(int i = 1 ; i < size ; i++) {
		if(minIndex == 0 && input.at(i) < input.at(i-1))
			minIndex = i;
		else if(input.at(i) < input.at(minIndex)) {
			minIndex = i;
		}
	}

	int start = 0;
	while(input.at(start) <= input.at(minIndex))
		start++;

	int maxIndex = size - 1;
	for(int i = size - 2 ; i >= 0 ; i--) {
		if(maxIndex == size - 1 && input.at(i) > input.at(i+1))
			maxIndex = i;
		else if(input.at(i) > input.at(maxIndex)) {
			maxIndex = i;
		}
	}

	int end = size - 1;
	while(input.at(end) >= input.at(maxIndex))
		end--;

	for(int i = start ; i <= end ; i++)
		cout << input.at(i) << " ";

	return 0;
}