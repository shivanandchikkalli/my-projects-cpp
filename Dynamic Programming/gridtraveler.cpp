#include <iostream>
#include<unordered_map>
#include<string>

using namespace std;

int MemCount = 0;

double gridTraveler(int row, int col)
{
    if(row == 0 || col == 0)
        return 0;
    else if(row == 1 || col == 1)
        return 1;
    else {
        return gridTraveler(row-1, col) + gridTraveler(row, col-1);
    }
}

unordered_map<string, unsigned long long> memo = {}; // used for the implementation of gridTravelerMem

unsigned long long gridTravelerMem(int row, int col)
{
	string key = to_string(row) + "," + to_string(col);
    if(memo.find(key) != memo.end())
        return memo[key];
    else if(row == 0 || col == 0)
        return 0;
    else if(row == 1 || col == 1)
        return 1;
    else {
        memo[key] = gridTravelerMem(row-1, col) + gridTravelerMem(row, col-1);
		MemCount++;
        return memo[key];
    }
}

unordered_map<string, unsigned long long> memo1 = {}; // used for the implementation of gridTravelerMem

unsigned long long gridTravelerMem1(int row, int col)
{
	string key1 = to_string(row) + "," + to_string(col);
	string key2 = to_string(col) + "," + to_string(row);
    if(memo1.find(key1) != memo1.end())
        return memo1[key1];
	else if(memo1.find(key2) != memo1.end())
        return memo1[key2];
    else if(row == 0 || col == 0)
        return 0;
    else if(row == 1 || col == 1)
        return 1;
    else {
        memo1[key1] = gridTravelerMem1(row-1, col) + gridTravelerMem1(row, col-1);
		MemCount++;
        return memo1[key1];
    }
}

int main()
{
    int row = 0;
    int col = 0;
	
	cout << "Enter row : ";
	cin >> row;
	cout << "Enter col : ";
	cin >> col;	
	
	cout << endl;
    
    unsigned long long count = gridTravelerMem(row, col);
    
	cout << "With Memoization" << endl;
    cout << "Path Count : " << count << endl;
	cout << "MemCount : " << MemCount << endl;
	
	MemCount = 0;
	cout << endl;
	
	cout << "With Memoization : Optimized" << endl;	
	count = gridTravelerMem1(row, col);
    cout << "Path Count : " << count << endl;
	cout << "Memery Count : " << MemCount << endl;
	
	cout << endl;
	
	cout << "Without Memoization" << endl;	
	count = gridTraveler(row, col);
    cout << "Path Count : " << count << endl;

    return 0;
}
