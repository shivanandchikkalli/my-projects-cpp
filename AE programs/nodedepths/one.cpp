using namespace std;

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

void depth(BinaryTree *node, int &result, int cDepth)
{
	if(node == NULL)
		return;
	result += cDepth;	
	depth(node->left, result, cDepth + 1);
	depth(node->right, result, cDepth + 1);
}

int nodeDepths(BinaryTree *root) {
	int result = 0;
	
	depth(root, result, 0);
	
  return result;
}