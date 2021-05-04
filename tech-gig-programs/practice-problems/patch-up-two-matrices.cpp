#include <iostream>
#include<vector>
using namespace std;
int main()
{
	vector<vector<vector<int>>> inputVectors = {};
	int row = 0;
	int col = 0;

	for(int k = 0 ; k < 2 ; k++)
	{
		vector<vector<int>> matrix = {};
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
			matrix.push_back(row);
		}
		inputVectors.push_back(matrix);
	}

	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0; j < col ; j++)
		{
			cout << inputVectors.at(0).at(i).at(j) + inputVectors.at(1).at(i).at(j);
			if(j+1 < col)
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}
