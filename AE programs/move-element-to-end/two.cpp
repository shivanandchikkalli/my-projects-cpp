#include <vector>

using namespace std;

// Time Complexity O(n) and Space Complexity O(1)
vector<int> moveElementToEnd(vector<int> array, int toMove) {
  
	int start = 0;
	int end = array.size() - 1;
	while(start < end)
	{
		while(start < end && array[end] == toMove)
			end--;
		if(array[start] == toMove)
			swap(array[start], array[end]);
		start++;
	}
	
  return array;
}