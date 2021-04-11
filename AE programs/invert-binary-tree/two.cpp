#include <vector>
#include<stack>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

// Time complexity O(n) and Space Complexity O(logn)
// space is consumed by system stack for recursive calls
void invertBinaryTree(BinaryTree *tree) {
  
	std::stack<BinaryTree*> st = {};
	if(tree)
		st.push(tree);
	while(!st.empty())
	{
		BinaryTree* temp = st.top();
		st.pop();
		swap(temp->left, temp->right);
		if(temp->left)
			st.push(temp->left);
		if(temp->right)
			st.push(temp->right);
	}
}