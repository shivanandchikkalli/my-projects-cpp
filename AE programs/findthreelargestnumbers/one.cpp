#include <vector>
#include <limits>
using namespace std;

void insertIntoArray(vector<int> &array, int value)
{
	if(value > array[2])
	{
		array[0] = array[1];
		array[1] = array[2];
		array[2] = value;
	}
	else if(value > array[1])
	{
		array[0] = array[1];
		array[1] = value;
	}
	else if(value > array[0])
		array[0] = value;
}

vector<int> findThreeLargestNumbers(vector<int> array) {
  vector<int> output = {INT_MIN, INT_MIN, INT_MIN};
	
	for(auto val : array)
	{
		insertIntoArray(output, val);
	}
	
  return output;
}