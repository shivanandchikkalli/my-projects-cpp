#include <vector>
using namespace std;

// Time Complexity O(n^2) and Space complexity O(1)
vector<int> selectionSort(vector<int> array) {
  
	for(int i = 0 ; i < array.size() ; i++)
	{
		int j = i + 1;
		int k = i;
		while(j < array.size())
		{
			if(array.at(j) < array.at(k))
				k = j;
			j++;
		}
		swap(array.at(i), array.at(k));
	}
	
  return array;
}