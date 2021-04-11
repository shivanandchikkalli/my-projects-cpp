using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

BinaryTree * inorderTraversal(BinaryTree* tree, BinaryTree *node)
{
	static bool flag = false;
	static BinaryTree * res = NULL;
	if(tree)
	{
		inorderTraversal(tree->left, node);	
		cout << tree->value << endl;
		if(tree->value == node->value)
			flag = true;
		else if(flag)
		{
			res = tree;
			flag = false;
		}
		inorderTraversal(tree->right, node);
	}
	return flag ? NULL : res;
}

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
	
  return inorderTraversal(tree, node);
}