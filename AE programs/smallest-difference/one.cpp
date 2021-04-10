#include <vector>
#include<algorithm>
using namespace std;

//Time Complexity O(nlogn) and Space Complexity O(1)
vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
	
	std::sort(arrayOne.begin(), arrayOne.end());
	std::sort(arrayTwo.begin(), arrayTwo.end());
	
	auto first = arrayOne.begin();
	auto second = arrayTwo.begin();
	
	vector<int> output = {};
	int prevDifference = INT_MAX;
	
	while(first != arrayOne.end() && second != arrayTwo.end())
	{
		int difference = 0;
		if((*first < 0 && *second > 0) || (*first > 0 && *second < 0))
			difference = abs(*first) + abs(*second);
		else
			difference = abs(abs(*first) - abs(*second));
		if(difference == 0)
			return {*first , *second};
		else if(prevDifference > difference){
			prevDifference = difference;
			output = {*first , *second};
		}
		if(*first < *second)
			first++;
		else
			second++;
	}
  return output;
}