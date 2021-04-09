#include <vector>
using namespace std;

// Time Complexity O(n^2) and Space Complexity O(1)
vector<int> insertionSort(vector<int> array) {
  
	for(int i = 1 ; i < array.size() ; i++)
	{
		int k = i - 1;
		int currentItem = array.at(i);
		while(k >= 0 && array.at(k) > currentItem)
		{
			array.at(k+1) = array.at(k);
			k--;
		}
		array.at(k + 1) = currentItem;
	}
  return array;
}