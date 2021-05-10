/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	unsigned int num = 0;
	cin >> num;

	int counter = 0;
	int result = 0;

	while(num / 10 != 0) {
		int rem = num % 10;
		result += pow(2, counter++) * rem;
		num /= 10;
	}
	result += pow(2, counter++) * num;

	cout << result << endl;

	return 0;
}