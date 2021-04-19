#include <vector>

using namespace std;

//Time Complexity O(n) and Space Complexity O(n)
vector<int> arrayOfProducts(vector<int> array) {
  int product = 0;
	int zeroCount = 0;
	for(int i = 0 ; i < array.size() ; i++){
		if(array.at(i) == 0)
			zeroCount++;
		else
			product = product == 0 ? array.at(i) : product * array.at(i);
	}
	
	vector<int> result = {};
	
	for(int i = 0 ; i < array.size() ; i++){
		if(zeroCount > 1 || (zeroCount == 1 && array.at(i) != 0))
			result.push_back(0);
		else if(array.at(i) == 0)
			result.push_back(product);
		else
			result.push_back(product / array.at(i));
	}
	
  return result;
}