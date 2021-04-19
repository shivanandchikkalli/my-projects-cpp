#include <vector>

using namespace std;

//Time Complexity O(n) and Space Complexity O(n)
vector<int> arrayOfProducts(vector<int> array) {
	vector<int> products = {};
	
	int baseProduct = 1;
	for(int i = 0 ; i < array.size() ; i++){
		products.push_back(baseProduct);
		baseProduct *= array.at(i);
	}
	
	baseProduct = 1;
	for(int i = array.size() - 1 ; i >= 0 ; i--){
		products.at(i) *= baseProduct;
		baseProduct *= array.at(i);
	}
	
  return products;
}