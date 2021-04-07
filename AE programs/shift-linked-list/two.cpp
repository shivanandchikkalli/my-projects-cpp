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
	LinkedList* second = head;
	
	int counter = 1;
	LinkedList* newTail = NULL;
	LinkedList* oldTail = NULL;	
	
	int size = 0;
	while(first)
	{
		oldTail = first;
		first = first->next;
		size++;
	}
	first = head;
	
	k = k % size;
	
	if(k == 0)
		return head;
	
	while(counter <= abs(k))
	{
		newTail = first;
		first = first->next;
		counter++;
	}
	
	if(k > 0)
	{
		newTail = NULL;
		while(first)
		{
			oldTail = first;
			first = first->next;
			newTail = second;
			second = second->next;
		}		
	}
	
	newTail->next = NULL;
	oldTail->next = head;
	head = k > 0 ? second : first;	
	
  return head;
}