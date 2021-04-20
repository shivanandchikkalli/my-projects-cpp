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

void ReverseInorderTraversal(BST* tree, int &k, int &result, bool &traverse, int &counter)
{
	if(tree){
		if(traverse)
			ReverseInorderTraversal(tree->right, k, result, traverse, counter);
		if(k == counter){
			result = tree->value;
			traverse = false;
		}
		counter++;
		if(traverse)
			ReverseInorderTraversal(tree->left, k, result, traverse, counter);		
	}
}

// Time Complexity O(n) and Space Complexity O(1)
int findKthLargestValueInBst(BST *tree, int k) {
	int result = 0;
	bool traverse = true;
	int counter = 1;
	ReverseInorderTraversal(tree, k, result, traverse, counter);
  return result;
}