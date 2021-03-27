#include<stack>
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

int nodeDepths(BinaryTree *root) {
  
	int sum = 0;
	int depth = 0;
	std::stack<pair<BinaryTree*, int>> stack;
	BinaryTree* temp = root;
	
	bool secondTime = false;
	
	while(stack.size() > 0 || temp)
	{
		if(temp)
		{
			sum += depth;
			stack.push(pair(temp, depth++));
			temp = temp->left;
		}
		else
		{
			temp = stack.top().first;
			depth = ++stack.top().second;
			stack.pop();
			temp = temp->right;
		}
	}
	
  return sum;
}
