#include <vector>
#include<unordered_map>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};

// Time Complexity o(n) and Space Complexity O(n)
LinkedList *findLoop(LinkedList *head) {
  std::unordered_map<LinkedList*, int> items = {};
	
	LinkedList* temp = head;
	while(items.find(temp) == items.end())
	{
		items.insert(pair<LinkedList*, int>(temp, temp->value));
		temp = temp->next;
	}
	
  return temp;
}