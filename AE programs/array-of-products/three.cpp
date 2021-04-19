#include <vector>

using namespace std;

//Time Complexity O(n) and Space Complexity O(n)
vector<int> arrayOfProducts(vector<int> array) {
	
	vector<int> leftRunningProducts = {};
	vector<int> rightRunningProducts = {};
	vector<int> products = {};
	
	int baseProduct = 1;
	for(int i = 0 ; i < array.size() ; i++){
		leftRunningProducts.push_back(baseProduct);
		baseProduct *= array.at(i);
	}
	
	baseProduct = 1;
	for(int i = array.size() - 1 ; i >= 0 ; i--){
		rightRunningProducts.push_back(baseProduct);
		baseProduct *= array.at(i);
	}
	
	for(int i = 0 ; i < array.size() ; i++){
		products.push_back(leftRunningProducts.at(i) * rightRunningProducts.at(array.size() -1 - i));
	}
	
  return products;
}