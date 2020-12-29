#include<stdio.h>
#include<stdlib.h>

#include "dll.h"

void removeItem(List* list, _Bool isFrontRemoval);
void addItem(List* list, void* value, _Bool isFrontAdd);
void destroyNode(Node* node);
Node* createNode();


List* createList()
{
	List* list = (List*)malloc(sizeof(List));
	if(list == NULL)
	{
		printf("Memory allocation failed...try again later\n");
		return NULL;
	}
	
	list->header = createNode();
	list->trailer = createNode();
	
	list->print_item = NULL;
	list->key_match = NULL;
	
	list->header->next = list->trailer;
	list->trailer->prev = list->header;
	
	return list;
}

_Bool IsEmpty(const List* list)
{		
	return list->header->next == list->trailer;
}

Node* createNode()
{
	Node* node = (Node*)malloc(sizeof(Node));
	if(node == NULL)
	{
		printf("Memory allocation failed...try again later\n");
		return NULL;
	}
	node->element = NULL;
	node->prev = NULL;
	node->next = NULL;
	
	return node;
}

void addFront(List* list, void* value)
{
	addItem(list, value, 1);
}

void addBack(List* list, void* value)
{
	addItem(list, value, 0);
}

void addItem(List* list, void* value, _Bool isFrontAdd)
{
	Node* node = createNode();
	node->element = value;
	
	if(IsEmpty(list))
	{
		list->header->next = node;
		node->prev = list->header;
		
		list->trailer->prev = node;
		node->next = list->trailer;
	}
	else if(isFrontAdd)
	{
		node->next = list->header->next;
		node->prev = list->header;
		
		list->header->next = node;
		node->next->prev = node;
		
	}
	else
	{
		node->prev = list->trailer->prev;
		list->trailer->prev->next = node;
		
		node->next = list->trailer;
		list->trailer->prev = node;
	}
}

void removeFront(List* list)
{
	removeItem(list, 1);
}

void removeBack(List* list)
{
	removeItem(list, 0);
}

void removeItem(List* list, _Bool isFrontRemoval)
{
	if(IsEmpty(list))
	{
		printf("\nList is empty.\n");
	}
	else if(isFrontRemoval)
	{
		Node* firstItem = list->header->next;
		
		list->header->next = firstItem->next;
		firstItem->next->prev = list->header;
		
		destroyNode(firstItem);
	}
	else
	{
		Node* lastItem = list->trailer->prev;
		
		list->trailer->prev = lastItem->prev;
		lastItem->prev->next = list->trailer;
		
		destroyNode(lastItem);		
	}	
}

void* getFirstItem(List* list)
{
	if(IsEmpty(list))
	{
		return NULL;
	}
	else
	{
		return list->header->next->element;
	}
}

void* getLastItem(List* list)
{
	if(IsEmpty(list))
	{
		return NULL;
	}
	else
	{
		return list->trailer->prev->element;
	}
}

List* reverse(List* list)
{
	if(IsEmpty(list))
	{
		printf("\nList is empty.\n");
	}
	else
	{
		Node* frontCursor = list->header->next;
		Node* backCursor = list->trailer->prev;	
		
		while(frontCursor != backCursor)
		{
			void* temp = backCursor->element;
			
			backCursor->element = frontCursor->element;
			frontCursor->element = temp;
			
			if(frontCursor != backCursor)
			{
				frontCursor = frontCursor->next;
				backCursor = backCursor->prev;		
			}
		}
		
	}
	return list;
}


void destroyList(List* list)
{
	while(!IsEmpty(list))
	{
		removeFront(list);
	}
	free(list->header);
	free(list->trailer);	
	free(list);
}

void destroyNode(Node* node)
{
	if(node != NULL)
	{
		free(node->element);
		free(node);
	}
}

void register_KeyMatch_Function(List* list, int (*key_match)(void*, void*))
{
	list->key_match = key_match;
}


void* searchElementByKey(List* list, void* key)
{
	if(IsEmpty(list))
	{
		return NULL;
	}
	else
	{
		Node* cursor = list->header->next;
		while(cursor != list->trailer)
		{
			if(list->key_match(cursor->element, key) == 1)
			{
				return cursor->element;
			}
			cursor = cursor->next;
		}
		return NULL;
	}
}


void register_print_function(List* list, void (*print_item)(void*))
{
	list->print_item = print_item;
}


void print_dll(List* list)
{
	if(IsEmpty(list))
	{
		printf("\nList is empty.\n");
	}
	else if(!list->print_item)
	{
		printf("\n print function is not defined...\n");
	}
	else
	{
		Node* cursor = list->header->next;
		while(cursor != list->trailer)
		{
			list->print_item(cursor->element);
			cursor = cursor->next;
		}
	}
}

/* this function can be written by checking the index whether is nearer to
end or start to reduce the time taken from n to n/2 */
Node* get_list_item_by_index(List* list, int index)
{
	Node* temp = list->header->next;
	while(index > 0)
	{
		temp = temp->next;
		index--;
	}
	return temp;
}

