#include <any>
#include <vector>

using namespace std;
// INPUT  ===>  array = [5, 2, [7, -1], 3, [6, [-13, 8], 4]]
// OUTPUT ===>  12 ==> calculated as: 5 + 2 + 2 * (7 - 1) + 3 + 2 * (6 + 3 * (-13 + 8) + 4)
int productSum(vector<any> array, int multiplier = 1) {
		int sum = 0;
  	for(auto val : array)
		{
			if(val.type() == typeid(vector<any>))
				sum += productSum(any_cast<vector<any>>(val), multiplier + 1);
			else
				sum += any_cast<int>(val);
		}
	
	return multiplier * sum;
}