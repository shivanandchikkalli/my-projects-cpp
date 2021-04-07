#include <vector>
using namespace std;

// Worst Case: Time Complexity O(n^2) and Space Complexity O(1)
// Best Case: Time Complexity O(n) and Space Complexity O(1)
// Avg Case: Time Complexity O(n^2) and Space Complexity O(1)
vector<int> bubbleSort(vector<int> array) {
	
	for(int i = 0 ; i < array.size() ; i++)
	{
		bool noSwaps = true;
		for(int j = 0 ; j + 1 < array.size() - i ; j++)
		{
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				noSwaps = false;
			}
		}
		if(noSwaps)
			break;
	}
  return array;
}