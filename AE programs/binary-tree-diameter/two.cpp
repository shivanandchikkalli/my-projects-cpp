using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

pair<int, int> getNodeHeightDiameter(BinaryTree *tree)
{
  if(tree == NULL)
		return pair<int, int>(0, 0);
	
	auto left = getNodeHeightDiameter(tree->left);
	auto right = getNodeHeightDiameter(tree->right);
	
	int diameterViaThisNode = left.first + right.first;
	int maxDiameterSoFar = max(left.second, right.second);
	
	int diameter = max(diameterViaThisNode, maxDiameterSoFar);
	int height = 1 + max(left.first, right.first);
	
	return pair<int, int>(height, diameter);
}

int binaryTreeDiameter(BinaryTree *tree) {

	auto res = getNodeHeightDiameter(tree);
	
  return res.second;
}