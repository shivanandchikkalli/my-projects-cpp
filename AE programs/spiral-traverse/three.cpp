using namespace std;

void traverse(int startRow, int endRow, int startColumn, int endColumn, 
										 vector<vector<int>> &array, vector<int> &res)
{	
	if(startRow <= endRow && startColumn <= endColumn){
		for(int i = startColumn; i <= endColumn && startRow <= endRow; i++){
			res.push_back(array.at(startRow).at(i));
		}

		for(int i = startRow+1; i <= endRow && startColumn <= endColumn; i++){
			res.push_back(array.at(i).at(endColumn));
		}

		for(int i = endColumn-1; i >= startColumn && startRow <= endRow; i--){
			if(startRow == endRow)
				break;
			res.push_back(array.at(endRow).at(i));
		}

		for(int i = endRow-1; i > startRow && startColumn <= endColumn; i--){
			if(startColumn == endColumn)
				break;
			res.push_back(array.at(i).at(startColumn));
		}

		startRow++;
		endRow--;
		startColumn++;
		endColumn--;

		traverse(startRow, endRow, startColumn, endColumn, array, res);
	}
}

vector<int> spiralTraverse(vector<vector<int>> array) {
  vector<int> res = {};
	int startRow = 0;
	int startColumn = 0;
	int endRow = array.size() - 1;
	int endColumn = array[startRow].size() - 1;
	
	traverse(startRow, endRow, startColumn, endColumn, array, res);
	
  return res;
}