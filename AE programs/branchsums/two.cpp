#include <stack>
#include <vector>
using namespace std;

// This is the class of the input root. Do not edit it.
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

vector<int> branchSums(BinaryTree *root) {
  
	BinaryTree* temp = root;
	int prevSum = 0;
	std::stack<BinaryTree*> st;
	vector<int> output = {};

	while(!st.empty() || temp != NULL)
	{
		if(temp != NULL && temp->left == NULL && temp->right == NULL)
		{
			output.push_back(temp->value + prevSum);
		}
		if(temp != NULL)
		{
			st.push(temp);
			temp->value += prevSum;
			prevSum = temp->value;
			temp = temp->left;
		}
		else
		{
			temp = st.top(); st.pop();
			prevSum = temp->value;
			temp = temp->right;
		}
	}
  return output;
}