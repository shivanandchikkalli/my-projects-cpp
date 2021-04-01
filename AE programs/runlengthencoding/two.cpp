using namespace std;

// Time Complexity O(n) and space Complexity O(n)
string runLengthEncoding(string str) {
  
	vector<char> output = {};
	int currentChar = str[0];
	int currentCharCount = 48;
	for(int i = 0 ; i < str.size(); i++)
	{
		if(str[i] == currentChar && currentCharCount <= 56)
			currentCharCount++;
		else {
			output.push_back(currentCharCount);
			output.push_back(currentChar);
			currentChar = str[i];
			currentCharCount = 49;
		}
	}
	output.push_back(currentCharCount);
	output.push_back(currentChar);
	
  return string(output.begin(), output.end());
}