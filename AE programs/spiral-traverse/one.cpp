using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
  vector<int> res = {};
	int startRow = 0;
	int startColumn = 0;
	int endRow = array.size() - 1;
	int endColumn = array[startRow].size() - 1;
	
	while(startRow <= endRow && startColumn <= endColumn)
	{
		for(int i = startColumn; i <= endColumn; i++){
			res.push_back(array.at(startRow).at(i));
		}
		
		for(int i = startRow+1; i <= endRow; i++){
			res.push_back(array.at(i).at(endColumn));
		}
		
		for(int i = endColumn-1; i >= startColumn; i--){
			if(startRow == endRow)
				break;
			res.push_back(array.at(endRow).at(i));
		}	

		for(int i = endRow-1; i > startRow; i--){
			if(startColumn == endColumn)
				break;
			res.push_back(array.at(i).at(startColumn));
		}		
		
		startRow++;
		endRow--;
		startColumn++;
		endColumn--;
	}

  return res;
}