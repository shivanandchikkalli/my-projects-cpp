#include <iostream>
#include<unordered_map>
#include<vector>
#include<cstdint>

using namespace std;

unordered_map<int, uintmax_t> memo = {};

uintmax_t fib(int n)
{
	if(n == 0) return 0;
	else if(n <= 2) return 1;
	else if(memo.find(n) != memo.end()) return memo[n];
	else{
		memo[n] = fib(n-2) + fib(n-1);
		return memo[n];
	}
	
}

int main()
{
	uintmax_t result = fib(50);
	
	cout << result << endl;
	
	return 0;
}