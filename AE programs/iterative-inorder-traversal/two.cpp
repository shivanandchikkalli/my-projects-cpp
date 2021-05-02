#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;
  BinaryTree *parent;

  BinaryTree(int value, BinaryTree *parent = nullptr);
  void insert(vector<int> values, int i = 0);
};

void iterativeInOrderTraversal(BinaryTree *tree,
                               void (*callback)(BinaryTree *tree)) {
  if(!tree)
		return;
	BinaryTree* previous = NULL;
	BinaryTree* current = tree;
	
	while(current) {
		BinaryTree* next = NULL;
		if(previous == NULL || previous == current->parent) {
			if(current->left != NULL)
				next = current->left;
			else {
				callback(current);
				next = current->right == NULL ? current->parent : current->right;
			}
		}
		else if(previous == current->left) {
			callback(current);
			next = current->right == NULL ? current->parent : current->right;
		}
		else
			next = current->parent;
		previous = current;
		current = next;
	}
}