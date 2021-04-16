#include <vector>
#include<algorithm>
using namespace std;

vector<int> mergeArray(vector<int> a, vector<int> b){
	int startNumber = a.at(0);
	int endNumber = a.at(1) > b.at(1) ? a.at(1) : b.at(1);
	return vector<int>{startNumber, endNumber};
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {

	std::sort(intervals.begin(), intervals.end());		
	
	vector<vector<int>> res = {};
	int startMergeIndex = -1;
	int endMergeIndex = -1;
	int FirstEndMergeValue = intervals.at(0).at(1);
	for(int i = 1; i < intervals.size() ; i++)
	{
		if(intervals.at(i).at(0) <= FirstEndMergeValue){
			startMergeIndex = startMergeIndex == -1 ?  i - 1 : startMergeIndex;
			endMergeIndex = i;
		}
		else if(startMergeIndex == -1 && endMergeIndex == -1){
			res.push_back(intervals.at(i-1));
		}
		else if(startMergeIndex != -1 && endMergeIndex != -1){
			res.push_back(mergeArray(intervals.at(startMergeIndex), intervals.at(endMergeIndex)));
			startMergeIndex = -1;
			endMergeIndex = -1;
		}
		FirstEndMergeValue = max(FirstEndMergeValue, intervals.at(i).at(1));
	}
	if(startMergeIndex != -1 && endMergeIndex != -1)
		res.push_back(mergeArray(intervals.at(startMergeIndex), intervals.at(endMergeIndex)));
	if(res.at(res.size()-1).at(1) < intervals.at(intervals.size()-1).at(1))
		res.push_back(intervals.at(intervals.size()-1));
	
  return res;
}