#include <iostream>
#include<unordered_map>
#include<vector>

using namespace std;


unordered_map<int, vector<int>> memo = {};

vector<int> howSum(int targetSum, std::vector<int> nums)
{
	if(targetSum == 0)
		return {};
	else if(targetSum > 0)
	{
		for(int num : nums)
		{
			int currentTarget = targetSum - num;
			vector<int> returnVector = howSum(currentTarget, nums);
			if(!(returnVector.size() == 1 && returnVector.at(0) == 0))  // if returning null, then this would be returnVector != null
			{
				returnVector.push_back(num);
				return returnVector;
			}
		}
	}
	
	return {0}; // simplifying return NULL,
}

vector<int> howSumMemo(int targetSum, std::vector<int> nums)
{
	if(targetSum == 0)
		return {};
	else if(memo.find(targetSum) != memo.end())
		return memo[targetSum];
	else if(targetSum > 0)
	{
		for(int num : nums)
		{
			int currentTarget = targetSum - num;
			vector<int> returnVector = howSumMemo(currentTarget, nums);
			if(!(returnVector.size() == 1 && returnVector.at(0) == 0))
			{
				returnVector.push_back(num);
				memo[targetSum] = returnVector;
				return memo[targetSum];
			}
		}
	}
	
	memo[targetSum] = {0};
	return memo[targetSum];
}

int main() {
    int targetSum = 300;
	std::vector<int> nums = {7,14};
	
	std::vector<int> resultArray = howSumMemo(targetSum, nums);
	
	std::cout << "targetSum : " << targetSum << std::endl;
	
	if(resultArray.size() == 1 && resultArray.at(0) == 0)
	{
		std::cout << "null";
	}
	else
	{
		std::cout << "Array : [ ";
		for(int num : resultArray)
			std::cout << num << " ";
		std::cout << "]";
	}

    return 0;
}
