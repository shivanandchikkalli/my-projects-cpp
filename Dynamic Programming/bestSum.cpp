#include <iostream>
#include<unordered_map>
#include<vector>
#include<limits.h>

using namespace std;


unordered_map<int, vector<int>> memo = {};

vector<int> howSumMemo(int targetSum, std::vector<int> nums)
{
	if(targetSum == 0)
		return {};
	else if(memo.find(targetSum) != memo.end())
		return memo[targetSum];
	else if(targetSum > 0)
	{
		vector<int> bestSum = {};
		for(int num : nums)
		{
			int currentTarget = targetSum - num;
			vector<int> returnVector = howSumMemo(currentTarget, nums);
			if(!(returnVector.size() == 1 && returnVector.at(0) == 0))
			{
				returnVector.push_back(num);
				if((bestSum.size() == 0) || (bestSum.size() > returnVector.size()))
					bestSum = returnVector;
			}
		}
		if(bestSum.size() != 0)
		{
			memo[targetSum] = bestSum;
			return memo[targetSum];	
		}
	}
	
	memo[targetSum] = {0};
	return memo[targetSum];
}

int main() {
    int targetSum = 8;
	std::vector<int> nums = {1,4,5};
	
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
