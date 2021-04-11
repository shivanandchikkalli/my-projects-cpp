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

BinaryTree* successor(BinaryTree* node)
{
	BinaryTree* temp = node->right;
	while(temp->left != NULL)
		temp = temp->left;
	return temp;
}

BinaryTree* rightMostParent(BinaryTree* node)
{
	BinaryTree* temp = node;
	while(temp->parent && temp->parent->right == temp)
		temp = temp->parent;
	return temp->parent;
}

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
  
	if(node->right)
		return successor(node);	
  return rightMostParent(node);
}