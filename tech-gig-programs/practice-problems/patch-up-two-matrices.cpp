/*Enter your code here. Read input from STDIN. Print your output to STDOUT

Patch Up Two Matrices
For this challenge, you need to take 2 matrices as an input from the stdin , add them and print the resultant matrix to the stdout.

Input Format
Two matrices to be taken as an input. 
For each matrix, on first line you need to tell that how many rows and columns your matrix need to have and these values should be separated by space. 
Then after that, each line will represent will represent each row and you need to enter numbers which each rows should have separated by a space. 

Constraints
1 <  (n,m) < 100
1 <  (p,q) < 100

Output Format
Print the resultant matrix to the stdout where each each line should represent 
Note : Please do not include space after the numbers which are in the last column as it will affect your submission and you will not get marks. 
each row and values in the row should be separated by a space. 


*/
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
