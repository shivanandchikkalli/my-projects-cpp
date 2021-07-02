#include <iostream>
#include<unordered_map>
#include<vector>
#include <string.h>

using namespace std;


unordered_map<string, bool> memo = {};

bool canConstruct(string target, vector<string> wordBank)
{
	if(target == "")
		return true;
	for(string word : wordBank)
	{
		if(word != "")
		{
			int position = target.find(word);
			if(position == 0) {
				string substring = target.substr(word.size());
				cout << "=========== Target =========== => " << target << "   ******   " << word << " trimmed , result => " << substring << endl;
				if(canConstruct(substring, wordBank))
					return true;
			}
		}
	}
	return false;
}

bool canConstructMomoized(string target, vector<string> wordBank)
{
	if(target == "")
		return true;
	else if(memo.find(target) != memo.end())
		return memo[target];
	for(string word : wordBank)
	{
		if(word != "")
		{
			int position = target.find(word);
			if(position == 0) {
				string substring = target.substr(word.size());
				cout << "=========== Target =========== => " << target << "   ******   " << word << " trimmed , result => " << substring << endl;
				if(canConstructMomoized(substring, wordBank)){
					memo[target] = true;
					return true;
				}
			}
		}
	}
	memo[target] = false;
	return false;
}



int main() {
	
    string target = "enterapotentpot"; //"abcdef"; //"skateboard";	
	
	vector<string> wordBank = {"a", "p", "ent", "enter", "", "ot", "o", "t"}; //{"ab", "abc", "cd", "def", "abcd"}; //{"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	
	bool result = canConstructMomoized(target, wordBank);
	
	cout << "Result : " << result << endl;
	
	result = canConstructMomoized("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e","ee","eee","eeee","eeeee","eeeeee","eeeeeee","eeeeeeee"});
	cout << "Result : " << result << endl;

    return 0;
}
