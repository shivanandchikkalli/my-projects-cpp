#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
  
	int startIndex = 0;
	int endIndex = array.size() - 1;
	
	while(startIndex <= endIndex)
	{
		int midIndex = (startIndex + endIndex) / 2;
		if(target < array[midIndex])
			endIndex = midIndex - 1;
		else if(target > array[midIndex])
			startIndex = midIndex + 1;
		else
			return midIndex;
	}
	
  return -1;
}
