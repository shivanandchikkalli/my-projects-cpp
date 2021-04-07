#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};  

// Time Complexity o(n) and Space Complexity O(1)
LinkedList *findLoop(LinkedList *head) {
  
	LinkedList* first = head->next;
	LinkedList* second = head->next->next;
	
	while(first != second)
	{
		first = first->next;
		second = second->next->next;
	}	
	first = head;
	while(first != second)
	{
		first = first->next;
		second = second->next;		
	}
	
  return first;
}