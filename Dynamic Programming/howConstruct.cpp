#include <iostream>
#include<unordered_map>
#include<vector>
#include <string.h>
#include<algorithm>

using namespace std;


unordered_map<string, vector<vector<string>>> memo = {};


vector<vector<string>> howConstruct(string target, vector<string> wordBank)
{
	if(target == "")
		return {{}};
	
	vector<vector<string>> finalResult = {};
	for(string word : wordBank)
	{
		if(word != "")
		{
			vector<string> array = {};
			int position = target.find(word);
			if(position == 0) {
				string substring = target.substr(word.size());
				auto result = howConstruct(substring, wordBank);  // {{'le', 'purp'}}
				for(int i = 0 ; i < result.size() ; i++)
					result.at(i).push_back(word);
				for(int i = 0 ; i < result.size() ; i++)
					finalResult.push_back(result.at(i));
			}
		}
	}
	return finalResult;
}

vector<vector<string>> howConstructMomoized(string target, vector<string> wordBank)
{
	if(target == "")
		return {{}};
	
	if(memo.find(target) != memo.end())
		return memo[target];
	
	vector<vector<string>> finalResult = {};
	for(string word : wordBank)
	{
		if(word != "")
		{
			vector<string> array = {};
			int position = target.find(word);
			if(position == 0) {
				string substring = target.substr(word.size());
				auto result = howConstructMomoized(substring, wordBank);
				for(int i = 0 ; i < result.size() ; i++)
					result.at(i).push_back(word);
				for(int i = 0 ; i < result.size() ; i++)
					finalResult.push_back(result.at(i));
			}
		}
	}
	memo[target] = finalResult;
	return finalResult;
}


int main() {
	
	
	//auto result = howConstruct("purple", {"purp", "p", "ur", "le", "purpl"});
	//auto result = howConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd", "ef", "c"});
	auto result = howConstructMomoized("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaz", {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa"});
	
	if(result.size() == 0 || (result.size() == 1 && result.at(0).size() == 0))
		cout << "Can't construct...";
	
	for(auto item : result)
	{
		cout << "[ ";
		for(int i = item.size() - 1 ; i >= 0 ; i--)
		{
			cout << item.at(i) << ", ";
		}
		cout << "]" << endl;
	}


    return 0;
}
