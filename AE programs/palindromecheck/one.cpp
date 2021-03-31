using namespace std;

// Time Complexity : O(n) and Space complexity O(1)
bool isPalindrome(string str) {
  
	for(int i = 0 ; i < str.size() / 2; i++)
	{
		if(str[i] != str[str.size()-1-i])
			return false;
	}
	
  return true;
}


/* 
Other solutions include creating new string with reversed characters and comparing later
Which takes O(n) and O(n) time and space complexity respectively. 
*/