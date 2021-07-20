using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
  LinkedList* root = linkedList;
	while(linkedList->next)
	{
		if(linkedList->value == linkedList->next->value)
			linkedList->next = linkedList->next->next;
		else
			linkedList = linkedList->next;
	}
	
  return root;
}
