#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target, int start, int end)
{
	if(start > end)
		return -1;
	int mid = (start + end) / 2;
	if(array[mid] == target)
		return mid;
	else if(target < array[mid])
		return binarySearch(array, target, start, mid - 1);
	else
		return binarySearch(array, target, mid + 1, end);
}

int binarySearch(vector<int> array, int target) {	
  return binarySearch(array, target, 0, array.size() - 1);
}