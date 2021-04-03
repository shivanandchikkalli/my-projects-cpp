#include<unordered_map>
using namespace std;

// Time Complexity O(n+n) i.e.,  O(n) , Space Complexity O(26) i.e., O(1) 
int firstNonRepeatingCharacter(string string) {

	unordered_map<char, int> charOccurances = {};

	for(char val : string)
	{
		if(charOccurances.find(val) == charOccurances.end())
			charOccurances.insert(pair<char, int>(val, 1));
		else
			charOccurances[val]++;
	}
	for(int i = 0; i < string.size(); i++)
	{
		if(charOccurances[string[i]] == 1)
			return i;
	}
  return -1;
}