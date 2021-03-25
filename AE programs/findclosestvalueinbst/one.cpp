#include <list>
#include <stdlib.h>
#include<limits>

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
  
	list<int> values;
	auto cItem = tree;
	
	while(cItem)
	{
		if(target <= cItem->value)
		{
			values.push_back(cItem->value);
			cItem = cItem->left;
		}
		else
		{
			values.push_front(cItem->value);
			cItem = cItem->right;
		}
	}
	int nearest = 0;
	int lastDiff = INT_MAX;
	for(auto val : values)
	{
		if(val == target)
			return target;
		if(lastDiff > abs(target - val))
		{
			nearest = val;
			lastDiff = abs(target - val);			
		}
	}	
  return nearest;
}