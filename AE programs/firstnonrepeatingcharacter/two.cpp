using namespace std;

// Time Complexity O(n^2) and Space Complexity O(1) 
int firstNonRepeatingCharacter(string string) {
  
	for(int i = 0 ; i < string.size(); i++)
	{
		int count = 0;
		for(int j = 0 ; j < string.size(); j++)
		{
			if(i != j && string[i] == string[j])
			{
				count++;
			}
		}
		if(count == 0)
			return i;
	}
  return -1;
}