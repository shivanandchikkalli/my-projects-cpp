using namespace std;

bool increasingArray(vector<int> array)
{
	for(auto i = array.begin() + 1; i < array.end() ; i++)
	{
		if(*i < *(i-1))
			return false;
	}
	return true;
}
bool decreasingArray(vector<int> array)
{
	for(auto i = array.begin() + 1; i < array.end() ; i++)
	{
		if(*i > *(i-1))
			return false;
	}
	return true;
}

// Time Complexity O(n) and Space complexity O(1)
bool isMonotonic(vector<int> array) {
  return decreasingArray(array) || increasingArray(array);
}