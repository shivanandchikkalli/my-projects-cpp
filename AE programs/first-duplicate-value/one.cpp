#include <vector>
#include<unordered_map>
using namespace std;

// Time Complexity O(n) and Space Complexity O(n)
int firstDuplicateValue(vector<int> array) { 
	
	unordered_map<int, int> storage = {};
	int resItem = -1;
	int resIndex = INT_MAX;
	
	for(int i = 0 ; i < array.size() ; i++)
	{
		if(storage.find(array.at(i)) == storage.end())
			storage.insert({array.at(i), -1});
		else
			return array.at(i);
	}	
	return resItem;
}