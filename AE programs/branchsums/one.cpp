using namespace std;

// This is the class of the input root. Do not edit it.
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

void calculateSum(BinaryTree *node, int prevSum, vector<int> &result)
{
	if(!node)
		return;
	int currentSum = prevSum + node->value;
	if(!node->left && !node->right)
	{
		result.push_back(currentSum);
		return;
	}
	calculateSum(node->left, currentSum, result);
	calculateSum(node->right, currentSum, result);
}

vector<int> branchSums(BinaryTree *root) 
{
  
	vector<int> output = {};

	calculateSum(root, 0, output);
	
	return output;
}
