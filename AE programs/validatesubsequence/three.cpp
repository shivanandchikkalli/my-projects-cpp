using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
	auto seqPtr = sequence.begin();
  for(auto i = array.begin() ; i < array.end() && seqPtr != sequence.end(); i++)
	{
		if(*seqPtr == *i)
			seqPtr++;
	}
	if(seqPtr == sequence.end())
		return true;
  return false;
}