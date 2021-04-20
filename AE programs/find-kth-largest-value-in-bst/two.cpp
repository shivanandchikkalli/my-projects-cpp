using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

void print(BST* tree)
{
	if(tree){
		print(tree->left);
		cout << tree->value << " ";
		print(tree->right);
	}
}

void invertBST(BST* tree)
{
	if(tree){
		swap(tree->left, tree->right);
		invertBST(tree->left);
		invertBST(tree->right);
	}
}

void inorderTraversal(BST* tree, int &k, int &result, bool &traverse, int &counter)
{
	if(tree && traverse){
		inorderTraversal(tree->left, k, result, traverse, counter);
		if(k == counter){
			result = tree->value;
			traverse = false;
		}
		counter++;
		inorderTraversal(tree->right, k, result, traverse, counter);		
	}
}

// Time Complexity O(n) and Space Complexity O(1)
int findKthLargestValueInBst(BST *tree, int k) {
	int result = 0;
	bool traverse = true;
	int counter = 1;
	invertBST(tree);
	inorderTraversal(tree, k, result, traverse, counter);
	invertBST(tree);
  return result;
}