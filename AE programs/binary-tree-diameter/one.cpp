#include<stack>
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

int Height(BinaryTree *tree)
{
	int x, y = 0;
	if(tree == NULL)
		return 0;
	x = Height(tree->left);
	y = Height(tree->right);
	return x > y ? x + 1 : y + 1;
}

int binaryTreeDiameter(BinaryTree *tree) {

	if(tree == NULL)
		return 0;
	int maxDiameter = 0;
	std::stack<BinaryTree*> st = {};
	if(tree)
		st.push(tree);
	while(!st.empty())
	{
		BinaryTree* temp = st.top();
		st.pop();
		int x = Height(temp->left);
		int y = Height(temp->right);
		
		if(maxDiameter < (x+y))
			maxDiameter = x + y;
		
		if(temp->left)
			st.push(temp->left);
		if(temp->right)
			st.push(temp->right);
	}
  return maxDiameter;
}