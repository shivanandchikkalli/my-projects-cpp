#include<vector>
using namespace std;

// Time Complexity O(n) and Space complexity O(n)
string caesarCypherEncryptor(string str, int key) {
  key = key % 26;
	if(key == 0)
		return str;	
	
	vector<char> oString = {};
	
	for(int i = 0 ; i < str.size(); i++)
	{
		int res = str[i] + key;
		if(res > 122)
			res -= 26;
		oString.push_back(res);
	}
	
  return string(oString.begin(), oString.end());
}