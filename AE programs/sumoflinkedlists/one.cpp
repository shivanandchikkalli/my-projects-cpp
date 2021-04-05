using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {	
	LinkedList* result = NULL;
	LinkedList* recent = NULL;
	int remainder = 0;
	
	LinkedList* first = linkedListOne;
	LinkedList* second = linkedListTwo;
	
	while(first != NULL || second != NULL || remainder != 0)
	{
		int currentSum = 0;
		if(first != NULL){
			currentSum += first->value;
			first = first->next;
		}
		if(second != NULL){
			currentSum += second->value;
			second = second->next;
		}
		currentSum += remainder;
		
		remainder = currentSum / 10;
		int currentValue = currentSum % 10;
		
		LinkedList* newItem = new LinkedList(currentValue);
		newItem->next = NULL;
		
		if(result == NULL)
			result = newItem;
		else
			recent->next = newItem;
		recent = newItem;
	}
	
  return result;
}