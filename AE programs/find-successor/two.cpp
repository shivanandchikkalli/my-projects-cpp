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

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
  
	if(node->left == NULL && node->right == NULL && node->parent == NULL)
		return NULL;
	if(node->right != NULL)
		return successor(node);
	if(node->right == NULL)
	{
		if(node->parent == NULL)
			return node->right;
		else if(node->parent->left == node)
			return node->parent;
		else if(node->parent->right == node)
			return node->parent->parent;
	}
  return nullptr;
}