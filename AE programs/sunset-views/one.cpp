using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction) {
	vector<int> res = {};
	vector<int> canSee(buildings.size(), 0);	
	int maxHeight = -1;
	
  if(direction == "EAST"){
		for(int i = buildings.size() - 1 ; i >= 0 ; i--){
			if(buildings.at(i) > maxHeight){
				canSee.at(i)++;
				maxHeight = buildings.at(i);
			}
		}
	}
	
  if(direction == "WEST"){
		for(int i = 0 ; i < buildings.size() ; i++){
			if(buildings.at(i) > maxHeight){
				canSee.at(i)++;
				maxHeight = buildings.at(i);
			}
		}
	}
	
	for(int x = 0 ; x < canSee.size() ; x++){
		if(canSee.at(x) == 1)
			res.push_back(x);
	}	
	
  return res;
}