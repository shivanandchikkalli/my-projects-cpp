#include <vector>
using namespace std;

void stackSort(vector<int> &st) {
	if(!st.empty()){
		int temp = st.back();
		st.pop_back();
		if(!st.empty() && temp < st.back())
		{
			int x = st.back();
			st.pop_back();
			st.push_back(temp);
			st.at(st.size() - 1) = temp;
			temp = x;
		}		
		stackSort(st);
		st.push_back(temp);
	}
}

// Time Complexity O(n^2) and space complexity O(n) this space is consumed by stack
vector<int> sortStack(vector<int> &stack) {
	
	for(int val : stack)
		stackSort(stack);	
	
  return stack;
}