#include <vector>
using namespace std;

// This is O(n) time complexity and O(n) space complexity
vector<int> sortedSquaredArray(vector<int> array) {
  vector<int> output(array.size(), 0);
	int i = 0, j = array.size() - 1, k = 1;
	
	while(i <= j)
	{
		int sSqrd = array[i] * array[i];
		int lSqrd = array[j] * array[j];
		if(sSqrd > lSqrd)
		{
			output[array.size() - k] = sSqrd;
			i++;
		}
		else
		{
			output[array.size() - k] = lSqrd;
			j--;
		}
		k++;
	}
	
  return output;
}