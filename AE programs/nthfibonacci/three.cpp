#include <unordered_map>

using namespace std;

// Time complexity O(n) and space complexity O(n)
int getFib(int n, unordered_map<int, int> &fib_store)
{
	if(fib_store.find(n) != fib_store.end())
		return fib_store[n];
	else
	{
		fib_store[n] = getFib(n-1, fib_store) + getFib(n-2, fib_store);
		return fib_store[n];
	}
}

int getNthFib(int n) {
  
	unordered_map<int, int> fib_store({{1, 0}, {2, 1}});
	
  return getFib(n, fib_store);
}