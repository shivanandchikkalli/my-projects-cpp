#include<stack>

using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction) {
  vector<int> res = {};
	std::stack<int> st = {};
	if(direction == "EAST"){
			for(int i = 0; i < buildings.size() ; i++) {	
			while(!st.empty() && buildings.at(i) >= buildings.at(st.top()))
				st.pop();
			st.push(i);
		}
	}

	if(direction == "WEST"){
		for(int i = buildings.size()-1; i >= 0 ; i--) {	
		while(!st.empty() && buildings.at(i) >= buildings.at(st.top()))
			st.pop();
		st.push(i);
		}	
	}
	
	while(!st.empty()){
		res.push_back(st.top());
		st.pop();
	}
	
	if(direction == "EAST")
		reverse(res.begin(), res.end());
	
  return res;
}