using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

void inorderTraversal(BST* tree, vector<int> &inorderTraversalResult)
{
	if(tree){
		inorderTraversal(tree->left, inorderTraversalResult);
		inorderTraversalResult.push_back(tree->value);
		inorderTraversal(tree->right, inorderTraversalResult);		
	}
}

// Time Complexity O(n) and Space Complexity O(n)
int findKthLargestValueInBst(BST *tree, int k) {
  vector<int> inorderTraversalResult = {};
	inorderTraversal(tree, inorderTraversalResult);
  return inorderTraversalResult.at(inorderTraversalResult.size() - k);
}