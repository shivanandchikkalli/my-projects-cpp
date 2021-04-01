#include<unordered_map>
using namespace std;

// Time Complexity O(n+m) and Space Complexity O(c)
// n => lenght of characters
// m => lenght of document
// c => number of unique characters in document
bool generateDocument(string characters, string document) {
	
	if(characters.size() < document.size())
		return false;
	
	unordered_map<char, int> output = {};
	
	for(char val : document)
	{
		if(output.find(val) == output.end())
			output.insert(pair<char, int>(val, 1));
		else
			output[val]++;
	}
	
	for(char chara : characters)
	{
		if(output.find(chara) != output.end()) {
			output[chara]--;
			if(output[chara] == 0)
				output.erase(output.find(chara));
		}
	}
	
  return output.size() == 0;
}