#include <iostream>
#include<unordered_map>
#include<vector>
#include <string.h>

using namespace std;


unordered_map<string, int> memo = {};


int canConstruct(string target, vector<string> wordBank)
{
	if(target == "")
		return true;
	int counter = 0;
	for(string word : wordBank)
	{
		if(word != "")
		{
			int position = target.find(word);
			if(position == 0) {
				string substring = target.substr(word.size());
				//cout << "=========== Target =========== => " << target << "   ******   " << word << " trimmed , result => " << substring << endl;
				if(canConstruct(substring, wordBank))
					counter++;
			}
		}
	}
	return counter;
}

int canConstructMomoized(string target, vector<string> wordBank)
{
	if(target == "")
		return true;
	else if(memo.find(target) != memo.end())
		return memo[target];
	memo[target] = 0;
	for(string word : wordBank)
	{
		if(word != "")
		{
			int position = target.find(word);
			if(position == 0) {
				string substring = target.substr(word.size());
				//cout << "=========== Target =========== => " << target << "   ******   " << word << " trimmed , result => " << substring << endl;
				if(canConstructMomoized(substring, wordBank)){
					memo[target]++;
				}
			}
		}
	}
	
	return memo[target];
}



int main() {
	
    string target = "enterapotentpot";	
	
	vector<string> wordBank = {"a", "p", "ent", "enter", "", "ot", "o", "t"}; //{"ab", "abc", "cd", "def", "abcd"}; //{"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	
	int result = canConstructMomoized(target, wordBank);
	
	cout << "enterapotentpot Result : " << result << endl;
	
	result = canConstructMomoized("purple", {"purp","p","ur","le","purpl"});
	cout << "purple Result : " << result << endl;
	
	result = canConstructMomoized("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e","ee","eee","eeee","eeeee","eeeeee","eeeeeee","eeeeeeee"});
	cout << "Result : " << result << endl;

    return 0;
}
