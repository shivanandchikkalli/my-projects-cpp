#include <vector>
using namespace std;

//Time Complexity O(n^2) and Space Complexity O(1)
vector<int> twoNumberSum(vector<int> array, int targetSum) {
  
	for(auto i = array.begin(); i < array.end(); i++)
	{
			for(auto j = i + 1; j < array.end(); j++)
			{
				if(targetSum == *i + *j)
				{
					return {*i, *j};
				}
			}
	}
  return {};
}