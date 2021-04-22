using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

void insert(BST* &node, int value)
{
	if(!node)
		node = new BST(value);
	else if(!node->left && !node->right){
		if(value < node->value)
			node->left = new BST(value);
		else
			node->right = new BST(value);
	}
	else if(value < node->value)
		insert(node->left, value);
	else
		insert(node->right, value);	
}

BST *reconstructBst(vector<int> preOrderTraversalValues) {
	BST* root = NULL;
	for(int val : preOrderTraversalValues)
		insert(root, val);
  return root;
}