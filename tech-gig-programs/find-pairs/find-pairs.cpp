/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int size = 0;
	cin >> size;

	vector<int> inputArray(size, 0);

	for(int i = 0 ; i < size ; i++) {
		int num = 0;
		cin >> num;
		inputArray[i] = num;
	}

	int target = 0;
	cin >> target;

	bool flag = false;

	int i = 0;
	int j = size - 1;

	std::sort(inputArray.begin(), inputArray.end());

	while(i < j) {
		if(inputArray[i] + inputArray[j] == target) {
			flag = true;
			break;
		}
		else if(inputArray[i] + inputArray[j] < target)
			i++;
		else if(inputArray[i] + inputArray[j] > target)
			j--;
	}

	if(flag)
		cout << "True";
	else
		cout << "False";
	return 0;
}
