#include <vector>
#include<queue>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string> *array) {
    
		std::queue<Node*> q = {};
		q.push(this);
		while(!q.empty()) {
			Node* temp = q.front(); 
			q.pop();
			array->push_back(temp->name);
			for(Node* item : temp->children)
				q.push(item);
		}
		
    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};