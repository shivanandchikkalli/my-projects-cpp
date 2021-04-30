#include <iostream>
#include<vector>

using namespace std;

int main() {

	vector<vector<int>> input = {
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, 25, -1, -1, -1, 5, -1},
		{-1, 25, -1, 12, -1, -1, -1, 10},
		{-1, -1, 12, -1, 8, -1, -1, -1},
		{-1, -1, -1, 8, -1, 16, -1, 14},
		{-1, -1, -1, -1, 16, -1, 20, 18},
		{-1, -1, -1, -1, -1, 20, -1, -1},
		{-1, -1, 10, -1, 14, 18, -1, -1}
	};

	vector<int> included(8, 0);
	int includedCount = 0;
	vector<int> array1 = {};
	vector<int> array2 = {};

	int min = INT_MAX;
	int row = 0;
	int col = 0;
	for(int i = 1 ; i < 8 ; i++)
	{
		for(int j = i ; j < 8 ; j++)
		{
			if(input[i][j] != -1 && input[i][j] < min) {
				min = input[i][j];
				row = i;
				col = j;
			}
		}
	}

	// cout << "min = " << min << " row = " << row << " col = " << col << endl;

	array1.push_back(row);
	array2.push_back(col);
	included.at(row) = 1;
	included.at(col) = 1;
	includedCount = 2;

	while(includedCount != 7)
	{
		min = INT_MAX;
		for(int val : array1) {
			for(int i = 1 ; i < 8 ; i++) {
				if(included.at(i) != 1 && input[val][i] != -1 && input[val][i] < min) {
					min = input[val][i];
					row = i;
					col = val;
				}
			}
		}
		for(int val : array2) {
			for(int i = 1 ; i < 8 ; i++) {
				if(included.at(i) != 1 && input[val][i] != -1 && input[val][i] < min) {
					min = input[val][i];
					row = i;
					col = val;
				}
			}
		}	
		// cout << "min = " << min << " row = " << row << " col = " << col << endl;
		array1.push_back(row);
		array2.push_back(col);
		if(included.at(row) == 0){
			included.at(row) = 1;
			includedCount++;
		}
		if(included.at(col) == 0){
			included.at(col) = 1;
			includedCount++;
		}
	}

	cout << "OUTPUT" << endl;

	for(int val : array1)
		cout << val << " ";
	cout << endl;

	for(int val : array2)
		cout << val << " ";
	cout << endl;	

	// for(int val : included)
	// 	cout << val << " ";
	// cout << endl;	

	return 0;
}
