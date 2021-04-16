#include <vector>
using namespace std;

vector<int> subarraySort(vector<int> array) {
	int start = -1;
	int end = -1;
	int i = 0;
	int j = 0;
	int smallestNum = 0;
	bool unordered = false;
  for(i = 1 ; i < array.size() ; i++){
		if(array.at(i) < array.at(smallestNum)){
			smallestNum = i;
			unordered = true;
		}
		else if(!unordered)
			smallestNum = i;
	}
	if(unordered)
	{
		for(j = 0 ; j < array.size() ; j++){
			if(array.at(j) >= array.at(smallestNum))
				break;
		}
		if(array.at(j) == array.at(smallestNum))
			j++;
		start = j;
		
		for(i = array.size() - 2; i >= 0 ; i--){
			if(array.at(i) > array.at(i+1))
				break;
		}
		if(i >= 0)
		{
			for(j = array.size() - 1 ; j >= 0 ; j--){
				if(array.at(j) <= array.at(i))
					break;
			}
			end = j;
		}
	}
	
	return {start, end};
}