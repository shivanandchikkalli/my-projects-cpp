/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include<unordered_map>
#include<climits>
#include<vector>
using namespace std;

bool isPrime(int num)
{
	if(num == 2)
		return true;
	else {
		for(int i = 2; i <= num/2 ; i++){
			if(num % i == 0)
				return false;
		}
		return true;
	}
}

int main()
{
	int testCases = 0;
	std::unordered_map<int, bool> primeNumbers = {};
	cin >> testCases;

	for(int i = 0 ; i < testCases ; i++)
	{
		int k = 0;
		cin >> k;
		int l = 0;
		cin >> l;

		while(k < l){
			if(primeNumbers.find(k) == primeNumbers.end()){
				bool res = isPrime(k);
				primeNumbers.insert(pair<int, bool>(k, res));
			}
			if(primeNumbers[k])
				break;
			k++;
		}
		while(l > k){
			if(primeNumbers.find(l) == primeNumbers.end()){
				bool res = isPrime(l);
				primeNumbers.insert(pair<int, bool>(l, res));
			}
			if(primeNumbers[l])
				break;
			l--;
		}
		if(k == l) {
			if(primeNumbers.find(l) == primeNumbers.end()){
				bool res = isPrime(l);
				primeNumbers.insert(pair<int, bool>(l, res));
			}
			if(primeNumbers[l])
				cout << 0 << endl;
			else
				cout << -1 << endl;
		}
		else if(k < l)
			cout << l - k << endl;
	}
	//Write code here
}