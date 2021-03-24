#include <vector>
#include <algorithm>
using namespace std;

// This is O(nlogn) time complexity and O(1) space complexity
vector<int> sortedSquaredArray(vector<int> &array) {
	for(auto &item : array)
	{
		if(item < 0)
			item = item * -1;
	}
	std::sort(array.begin(), array.end());
	for(auto &item : array)
	{
		item = item * item;
	}
  return array;
}