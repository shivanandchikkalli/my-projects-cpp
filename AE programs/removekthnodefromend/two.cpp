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
  int counter = 1;
	LinkedList* node = head;
	while(counter <= k)
	{
		node = node->next;
		counter++;
	}
	
	//this happens when k = number of elements i.e., when first element supposed to be deleted
	if(node == nullptr) {
		head->value = head->next->value;
		head->next = head->next->next;
		return;
	}
	
	LinkedList* secondNode = head;
	while(node->next)
	{
		secondNode = secondNode->next;
		node = node->next;
	}
	
	secondNode->next = secondNode->next->next;
	
}
