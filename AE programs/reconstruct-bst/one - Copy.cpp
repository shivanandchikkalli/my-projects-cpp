using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

BST *reconstructBst(vector<int> preOrderTraversalValues) {
  if(preOrderTraversalValues.size() == 0)
		return NULL;
	int rootRightItemIndex = 1;
	for( ; rootRightItemIndex < preOrderTraversalValues.size() ; rootRightItemIndex++){
		if(preOrderTraversalValues.at(0) <= preOrderTraversalValues.at(rootRightItemIndex))
			break;
	}
	
	BST* newNode = new BST(preOrderTraversalValues.at(0));
	newNode->left = reconstructBst(vector<int>(preOrderTraversalValues.begin() + 1, preOrderTraversalValues.begin() + rootRightItemIndex));
	newNode->right = reconstructBst(vector<int>(preOrderTraversalValues.begin() + rootRightItemIndex, preOrderTraversalValues.end()));
	
  return newNode;
}