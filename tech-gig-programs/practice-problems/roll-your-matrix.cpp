#include <iostream>
#include<vector>
using namespace std;
int main()
{
	vector<vector<int>> inputVectors = {};
	int row = 0;
	int col = 0;

	cin >> row;
	cin >> col;

	for(int i = 0 ; i < row ; i++)
	{
		vector<int> row = {};
		for(int j = 0; j < col ; j++)
		{
			int value = 0;
			cin >> value;
			row.push_back(value);
		}
		inputVectors.push_back(row);
	}

	for(int i = 0 ; i < col ; i++)
	{
		for(int j = 0; j < row ; j++)
		{
			cout << inputVectors.at(j).at(i);
			if(j+1 < row)
				cout << " ";			
		}
		cout << endl;
	}

	return 0;
}