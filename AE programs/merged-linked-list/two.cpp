#include <vector>

using namespace std;

// This is an input class. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo) {
	
	LinkedList* first = headOne;
	LinkedList* second = headTwo;
	
	LinkedList* rHead = NULL;
	LinkedList* prev = NULL;
	
	while(first && second)
	{
		if(first->value <= second->value)
		{
			if(rHead == NULL)
				rHead = first;
			else
				prev->next = first;
			prev = first;
			first = first->next;
		}
		else
		{
			if(rHead == NULL)
				rHead = second;
			else
				prev->next = second;
			prev = second;
			second = second->next;
		}
	}
	
	if(first == NULL)
		prev->next = second;
	else if(second == NULL)
		prev->next = first;
	
  return rHead;
}