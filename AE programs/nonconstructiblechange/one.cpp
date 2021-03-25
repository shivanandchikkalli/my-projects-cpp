#include <vector>
#include <algorithm>
using namespace std;

/* Given an array of positive integers representing the values of coins in your
  possession, write a function that returns the minimum amount of change (the
  minimum sum of money) that you cannot create. The given coins can have
  any positive integer value and aren't necessarily unique (i.e., you can have
  multiple coins of the same value). */
// This solution takes O(nlogn) time and O(1) space
int nonConstructibleChange(vector<int> coins) {
  
	std::sort(coins.begin(), coins.end());
	
	int smallestSum = 1;
	
	for(int val : coins)
	{
		if(val > smallestSum)
			return smallestSum;
		smallestSum += val;
	}
	
  return smallestSum;
}