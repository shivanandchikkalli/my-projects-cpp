#include <vector>
using namespace std;


// If adding properties to LinkedList class is allowed
class LinkedList {
public:
  int value;
  int visited = 0; // this is added to record the visit while traversing
  LinkedList *next;

  LinkedList(int value);
};

LinkedList *findLoop(LinkedList *head) {
	LinkedList* temp = head;
	while(temp->visited == 0)
	{
		temp->visited = 1;
		temp = temp->next;
	}
	
  return temp;
}