#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k) {	
	int size = 0;
	LinkedList* node = head;
	while(node)
	{
		size++;
		node = node->next;
	}
	int indexFromFront = size - k;
	
	if(indexFromFront == 0) {
		head->value = head->next->value;
		head->next = head->next->next;
		return;
	}
	
	LinkedList* prevNode = NULL;
	node = head;
	for(int i = 0 ; i < indexFromFront; i++)
	{
		prevNode = node;
		node = node->next;
	}
	prevNode->next = node->next;
}