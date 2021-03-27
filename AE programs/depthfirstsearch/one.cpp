#include <vector>
using namespace std;

class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> depthFirstSearch(vector<string> *array) {
    
		vector<string> output = {};

		dfs(this, output);
		
    return output;
  }
	
	void dfs(Node* node, vector<string> &output)
	{
		if(node)
		{
			output.push_back(node->name);
			for(auto item : node->children)
			{
				dfs(item, output);
			}			
		}
	}

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};