#include <vector>
#include<queue>
#include<cmath>
using namespace std;

vector<int> radixSort(vector<int> array) {
	
	if(array.size() < 2)
		return array;
  
	int max = INT_MIN;
	for(int val : array) {
		if(val > max)
			max = val;
	}
	
	int counter = 1;
	while(max / 10 != 0) {
		counter++;
		max /= 10;
	}
	
	vector<queue<int>> radix(10);
	
	for(int i = 0 ; i < counter ; i++) {
		for(int val : array) {
			int index = (val / static_cast<int>(pow(10, i))) % 10;
			radix.at(index).push(val);
		}
		int count = 0;
		for(int j = 0 ; j < radix.size() ; j++) {
			while(!radix.at(j).empty()) {
				array.at(count++) = radix.at(j).front();
				radix.at(j).pop();
			}
		}
	}	
	
  return array;
}