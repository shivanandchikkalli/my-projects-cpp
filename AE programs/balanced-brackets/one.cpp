#include<stack>
#include<unordered_map>
using namespace std;

bool balancedBrackets(string str) {
  
	std::stack<char> st = {};
	std::unordered_map<char, char> charMappings = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

	for(char item : str){
		if(item != '(' && item != ')' && item != '[' && item != ']' && item != '{' && item != '}')
			continue;
		if(st.empty() || item != charMappings[st.top()])
			st.push(item);
		else if(item == charMappings[st.top()])
			st.pop();
	}

  return st.empty();
}