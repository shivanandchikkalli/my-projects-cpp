#include <vector>
#include <algorithm>
using namespace std;

// This is O(nlogn) time complexity and O(n) space complexity
vector<int> sortedSquaredArray(vector<int> array) {
	vector<int> output = {};
	for(auto const &item : array)
	{
		output.push_back((int)(item * item));
	}
	std::sort(output.begin(), output.end());
  return output;
}
