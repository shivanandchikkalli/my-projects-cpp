#include <vector>
using namespace std;

vector<vector<int>> getP(vector<int> array)
{
	if(array.size() == 1)
		return {array};
	if(array.size() == 2){
		return {{array.at(0), array.at(1)}, {array.at(1), array.at(0)}};
	}
	vector<vector<int>> res = {};
	for(int i = 0 ; i < array.size() ; i++) {
		vector<int> passArray = {};
		for(int j = 0 ; j < array.size(); j++){
			if(i != j)
				passArray.push_back(array.at(j));
		}
		
		vector<vector<int>> permu = getP(passArray);
		for(int k = 0 ; k < permu.size() ; k++) {
			vector<int> one = {};
			one.push_back(array.at(i));
			permu.at(k).insert(permu.at(k).begin(), one.begin(), one.end());
			res.push_back(permu.at(k));
		}
	}
	return res;
}

vector<vector<int>> getPermutations(vector<int> array) {	
  return getP(array);
}