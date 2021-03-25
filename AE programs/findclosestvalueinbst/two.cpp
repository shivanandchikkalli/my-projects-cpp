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
	auto cItem = tree;
	
	int nearest = 0;
	int lastDiff = INT_MAX;
	
	while(cItem)
	{
		if(lastDiff > abs(target - cItem->value))
		{
			lastDiff = abs(target - cItem->value);	
			nearest = cItem->value;
		}
		
		if(target <= cItem->value)
		{
			cItem = cItem->left;
		}
		else
		{
			cItem = cItem->right;
		}
	}
  return nearest;
}