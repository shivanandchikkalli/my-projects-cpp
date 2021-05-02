#include <vector>
#include<stack>
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
	
	std::stack<BinaryTree*> st = {};
	BinaryTree* temp = tree;
	while(!st.empty() || temp != NULL) {
		if(temp != NULL) {
			st.push(temp);
			temp = temp->left;
		}
		else {
			temp = st.top();
			st.pop();
			callback(temp);
			temp = temp->right;
		}
	}
}