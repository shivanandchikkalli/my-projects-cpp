using namespace std;

// Time Complexity O(n) and Space complexity O(n)
string caesarCypherEncryptor(string str, int key) {
  key = key % 26;
	if(key == 0)
		return str;	
	
	string output = "";
	
	for(int i = 0 ; i < str.size(); i++)
	{
		int res = str[i] + key;
		if(res > 122)
			res -= 26;
		output += res;
	}
	
  return output;
}