using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

// Time Complexity O(n) and Space Complexity O(1)
LinkedList *shiftLinkedList(LinkedList *head, int k) {
  
	LinkedList* first = head;	
	int size = 1;
	while(first->next && size++)
		first = first->next;
	
	int diff = abs(k) % size;
	if(diff == 0)
		return head;
	
	int newHeadPosition = k > 0 ? size - diff : diff;
	
	LinkedList* newTail = head;
	for(int i = 1; i < newHeadPosition; i++)
		newTail = newTail->next;
	
	first->next = head;
	head = newTail->next;
	newTail->next = NULL;
	
  return head;
}