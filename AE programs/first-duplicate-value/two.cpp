#include <vector>
using namespace std;

// Time Complexity O(n) and Space Complexity O(1)
int firstDuplicateValue(vector<int> array) { 
	
	for(int val : array) {
		if(array[abs(val) - 1] < 0)
			return abs(val);
		array[abs(val) - 1] *= -1;
	}
	
	return -1;
}