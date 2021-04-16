class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool validate(BST* tree, int minValue, int maxValue)
{
	if(tree->value < minValue || tree->value >= maxValue)
		return false;
	if(tree->left && !validate(tree->left, minValue, tree->value))
		return false;
	if(tree->right && !validate(tree->right, tree->value, maxValue))
		return false;	
	return true;
}

bool validateBst(BST *tree) {
	
  return validate(tree, INT_MIN, INT_MAX);
	
}