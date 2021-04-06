using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

// Time Complexity O(n) and Space Complexity O(1)
LinkedList *reverseLinkedList(LinkedList *head) {
  
	LinkedList* current = head;
	LinkedList* next = head->next;
	
	current->next = NULL;
	
	while(next)
	{
		LinkedList* temp = next->next;
		next->next = current;
		current = next;
		next = temp;
	}
	
  return current;
}