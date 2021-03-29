using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
  
	LinkedList* prevItem = NULL;
	auto cItem = linkedList;
	
	while(cItem != NULL)
	{
		if(prevItem && prevItem->value == cItem->value)
			prevItem->next = cItem->next;
		else
			prevItem = cItem;
		cItem = cItem->next;
	}
	
  return linkedList;
}
