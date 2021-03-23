using namespace std;

// This solution assumes that the sub sequence elements order is not related to main array order
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
	if(sequence.size() > array.size())
		return false;
	for(auto i = sequence.begin(); i < sequence.end(); i++)
	{
		bool isPresent = false;
		for(auto j = array.begin(); j < array.end(); j++)
		{
			if(*i == *j)
			{
				isPresent = true;
				array.erase(j);
				break;
			}
		}
		if(!isPresent)
			return false;
	}
  return true;
}