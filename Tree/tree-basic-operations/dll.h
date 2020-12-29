#include<stdio.h>

typedef struct Node
{
	void* element;
	struct Node* prev;
	struct Node* next;
}Node;

typedef struct List
{
	Node* header;
	Node* trailer;
	int (*key_match)(void*, void*);
	void (*print_item)(void*);
}List;


List* createList();

_Bool IsEmpty(const List* list);

void addFront(List* list, void* value);

void addBack(List* list, void* value);

void removeFront(List* list);

void removeBack(List* list);

void* getFirstItem(List* list);

void* getLastItem(List* list);

List* reverse(List* list);

void destroyList(List* list);

void register_KeyMatch_Function(List* list, int (*key_match)(void*, void*));

void register_print_function(List* list, void (*print_item)(void*));

void* searchElementByKey(List* list, void* key);

void print_dll(List* list);

Node* get_list_item_by_index(List* list, int index);
