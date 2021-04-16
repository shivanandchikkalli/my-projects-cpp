#include <vector>
using namespace std;

bool isOutOfOrder(int i, vector<int> ar)
{
	if(i==0)
		return ar.at(i) > ar.at(i+1);
	if(i==ar.size()-1)
		return ar.at(i) < ar.at(i-1);
	return ar.at(i) > ar.at(i+1) || ar.at(i) < ar.at(i-1);
}

vector<int> subarraySort(vector<int> array) {
  int minNumber = INT_MAX;
	int maxNumber = INT_MIN;
	for(int i = 0 ; i < array.size() ; i++)
	{
		if(isOutOfOrder(i, array)){
			minNumber = min(minNumber, array.at(i));
			maxNumber = max(maxNumber, array.at(i));
		}
	}
	if(minNumber == INT_MAX)
		return {-1, -1};
	int i = 0;
	while(minNumber >= array.at(i))
		i++;
	int j = array.size() - 1;
	while(maxNumber < array.at(j))
		j--;
	
  return {i, j};
}