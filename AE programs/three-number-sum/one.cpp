#include <vector>
#include<algorithm>
using namespace std;

// Time Complexity O(n^2) and Space Complexity O(n)
vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  	
	std::sort(array.begin(), array.end());
	vector<vector<int>> output = {};
	
	for(auto left = array.begin() ; left < array.end() ; left++)
	{
		auto current = left + 1;
		auto right = array.end() - 1;		
		int offset = targetSum - *left;
		while(current != array.end() && current != right)
		{
			if(*current + *right == offset){
				output.push_back({*left, *current, *right});
				current++;
			}
			else if(*current + *right < offset)
				current++;
			else
				right--;
		}
	}
  return output;
}