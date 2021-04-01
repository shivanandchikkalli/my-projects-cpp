using namespace std;

// Time Complexity O(n) and space Complexity O(n)
string runLengthEncoding(string str) {
  
	string output = "";
	int currentChar = str[0];
	int currentCharCount = 48;
	for(int i = 0 ; i < str.size(); i++)
	{
		if(str[i] == currentChar && currentCharCount <= 56)
			currentCharCount++;
		else {
			output += currentCharCount;
			output += currentChar;
			currentChar = str[i];
			currentCharCount = 49;
		}
	}
	output += currentCharCount;
	output += currentChar;
	
  return output;
}