using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction) {
	vector<int> res = {};
	int maxHeight = -1;
	
  if(direction == "EAST"){
		for(int i = buildings.size() - 1 ; i >= 0 ; i--){
			if(buildings.at(i) > maxHeight){
				res.push_back(i);
				maxHeight = buildings.at(i);
			}
		}
		reverse(res.begin(), res.end());
	}
	
  if(direction == "WEST"){
		for(int i = 0 ; i < buildings.size() ; i++){
			if(buildings.at(i) > maxHeight){
				res.push_back(i);
				maxHeight = buildings.at(i);
			}
		}
	}	
	
  return res;
}