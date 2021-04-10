#include <vector>

using namespace std;

// Time Complexity O(n) and Space Complexity O(1)
vector<int> moveElementToEnd(vector<int> array, int toMove) {

	int counter = 0;	
	if(array.size() == 0)
		return {};
	
	while(array[array.size() - 1 - counter] == toMove)
		counter++;
	for(int i = 0 ; i + 1 < array.size() - counter ; i++)
	{
		if(toMove == array[i])
		{
			swap(array[i], array[array.size() - 1 - counter]);
			
			while(array[array.size() - 1 - counter] == toMove)
				counter++;
		}
	}
  return array;
}