#include <vector>
#include <map>
using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  std::map<string, int> result;
	
	for(int i = 0 ; i < competitions.size() ; i++)
	{
		for(int comp = 0 ; comp < 2 ; comp++)
		{
			int score = 0;
			if((results[i] == 0 && comp == 1) || (results[i] == 1 && comp == 0))
				score = 3;
			if(result.find(competitions[i][comp]) == result.end())
				result.insert(pair<string, int> (competitions[i][comp], score));
			else
			{
				auto itr = result.find(competitions[i][comp]);
				itr->second += score;
			}
		}
	}
	auto winner = result.begin();
	for (auto itr = result.begin(); itr != result.end(); itr++) 
	{
		if(winner->second < itr->second)
			winner = itr;
	}
	
  return winner->first;
}