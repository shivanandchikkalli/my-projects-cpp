#include <iostream>
#include<unordered_map>
#include<vector>

using namespace std;

unordered_map<int, bool> memo = {};

bool canSum(int targetSum, std::vector<int> nums)
{
	if(memo.find(targetSum) != memo.end())
		return memo[targetSum];
	else if(targetSum == 0)
		return true;
	else if(targetSum > 0)
	{
		for(int num : nums)
		{
			int currentTarget = targetSum - num;
			if(canSum(currentTarget, nums))
			{
				memo[targetSum] = true;
				return memo[targetSum];
			}
		}
	}
	
	memo[targetSum] = false;
	return memo[targetSum];
}

int main() {
    int targetSum = 300;
	std::vector<int> nums = {7,14};
	
	std::cout << "targetSum : " << targetSum << std::endl;
	
	std::cout << "Array : ";
	for(int num : nums)
		std::cout << num << " ";
	
	std::cout << std::endl << "canSum ? : " << canSum(targetSum, nums) << std::endl;

    return 0;
}
