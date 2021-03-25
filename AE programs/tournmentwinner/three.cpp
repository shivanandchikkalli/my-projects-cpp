#include <vector>
#include <set>
using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  
	set<string> teams;
	vector<string> winners;
	string winnerTeam = "";
	int i = 0;
	for(auto comp : competitions)
	{
		if(results[i] == 0)
			winners.push_back(comp[1]);
		else
			winners.push_back(comp[0]);
		teams.insert(comp[0]);
		teams.insert(comp[1]);
		i++;
	}	
	
	int pCount = 0;
	for(auto team : teams)
	{
		int count = 0;
		for(auto winner : winners)
		{
			if(winner == team)
			{
				count++;
			}
		}
		if(pCount < count)
		{
			winnerTeam = team;
			pCount = count;
		}
	}
		
  return winnerTeam;
}