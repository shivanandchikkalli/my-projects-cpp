/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include<cmath>
using namespace std;

unsigned long long int CalculatePower(int num, int power)
{
	if(power == 0)
		return 1;
	else if(power == 1)
		return num;
	return num * CalculatePower(num, power-1);
}

int main()
{
	int num = 0;
	int power = 0;

	cin >> num;
	cin >> power;

	cout << CalculatePower(num, power);

	return 0;
}