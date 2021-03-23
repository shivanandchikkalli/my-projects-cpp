using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
	auto seqPtr = sequence.begin();
	auto arrPtr = array.begin();

	while(seqPtr < sequence.end() && arrPtr < array.end())
	{
		if(*seqPtr == *arrPtr)
			seqPtr++;
		arrPtr++;
	}
	if(seqPtr == sequence.end())
		return true;
	
	return false;
}
