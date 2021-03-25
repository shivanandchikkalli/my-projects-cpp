#include <vector>
#include <map>
using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  std::map<string, int> result;
	string currentWinnerName = "";
	int currentWinnerScore = 0;
	result.insert(pair<string, int>(currentWinnerName, currentWinnerScore));
	
	for(int i = 0 ; i < competitions.size() ; i++)
	{
		for(int comp = 0 ; comp < 2 ; comp++)
		{
			int score = 0;
			if((results[i] == 0 && comp == 1) || (results[i] == 1 && comp == 0))
				score = 3;
			if(result.find(competitions[i][comp]) == result.end())
			{
				result.insert(pair<string, int> (competitions[i][comp], score));
				if(score > currentWinnerScore)
				{
					currentWinnerScore = score;
					currentWinnerName =	competitions[i][comp];
				}			
			}
			else
			{
				auto itr = result.find(competitions[i][comp]);
				itr->second += score;
				if(itr->second > currentWinnerScore)
				{
					currentWinnerScore = itr->second;
					currentWinnerName = itr->first;
				}
			}
		}
	}
	
  return currentWinnerName;
}