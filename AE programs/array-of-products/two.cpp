#include <vector>

using namespace std;

//Time Complexity O(n^2) and Space Complexity O(n)
vector<int> arrayOfProducts(vector<int> array) {
	vector<int> results = {};
	for(int i = 0 ; i < array.size() ; i++)
	{
		int currentProduct = 1;
		for(int j = 0 ; j < array.size(); j++)
		{
			if(i != j)
				currentProduct *= array[j];
		}	
		results.push_back(currentProduct);
	}
	
  return results;
}