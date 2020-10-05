#include<iostream>

#include "sll.h"

template <typename E>
SList<E>::SList() : head(NULL) {}


template <typename E>
SList<E>::~SList()
{
	while(!empty())
	{
		removeFront();
	}
}


template <typename E>
bool SList<E>::empty() const
{
	return head==NULL;
}


template <typename E>
const E& SList<E>::front() const
{
	return head->element;
}


template <typename E>
void SList<E>::addFront(const E& e)
{
	SNode<E>* newNode = new SNode<E>;
	newNode->element = e;
	newNode->next = head;
	head = newNode;
}

template <typename E>
void SList<E>::removeFront()
{
	SNode<E>* oldHead = head;
	head = oldHead->next;
	delete oldHead;
}
