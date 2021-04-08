#include <vector>
#include <algorithm>
using namespace std;

//Time Complexity O(nlogn) and Space Complexity O(1)
vector<int> twoNumberSum(vector<int> array, int targetSum) {
	std::sort(array.begin(), array.end());
	
	auto frontPtr = array.begin();
	auto backPtr = array.end() - 1;
	
	while(frontPtr != backPtr)
	{
		if(*frontPtr + *backPtr == targetSum)
			return {*frontPtr , *backPtr};
		else if(*frontPtr + *backPtr < targetSum)
			frontPtr++;
		else
			backPtr--;
	}
	
  return {};
}