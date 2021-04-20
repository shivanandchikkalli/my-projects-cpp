#include <vector>
using namespace std;

// Time Complexity O(n^2) and Space Complexity O(n)
int firstDuplicateValue(vector<int> array) { 
	int resItem = -1;
	int resIndex = INT_MAX;	
	for(int i = 0 ; i < array.size() ; i++)
	{
		for(int j = i + 1 ; j < array.size() ; j++){
			if(array.at(i) == array.at(j) && resIndex > j){
				resItem = array.at(i);
				resIndex = j;
			}
		}
	}
	
	return resItem;
}