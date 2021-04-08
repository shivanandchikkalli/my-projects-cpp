#include <vector>
#include<unordered_set>
using namespace std;

//Time Complexity O(n) and Space Complexity O(n)
vector<int> twoNumberSum(vector<int> array, int targetSum) {
  std::unordered_set<int> unSet = {};
	for(int num : array)
	{
		int reqNum = targetSum - num;
		if(unSet.find(reqNum) != unSet.end())
			return {reqNum, num};
		else
			unSet.insert(num);
	}
  return {};
}