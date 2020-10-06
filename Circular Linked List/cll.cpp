#include<iostream>

#include "cll.h"


template <typename T>
CList<T>::CList() : cursor(NULL) {}



template <typename T>
CList<T>::~CList()
{
	while(cursor != NULL)
	{
		remove();
	}
}


template <typename T>
bool CList<T>::empty()
{
	return cursor == NULL;
}


template <typename T>
const T& CList<T>::front() const
{
	return cursor->next->element;
}


template <typename T>
const T& CList<T>::back() const
{
	return cursor->element;
}


template <typename T>
void CList<T>::advance()
{	
	cursor = cursor->next;
}


template <typename T>
void CList<T>::add(const T& t)
{
	CNode<T>* newNode = new CNode<T>;
	newNode->element = t;
	if(cursor == NULL)
	{
		cursor = newNode;
		cursor->next = cursor;
	}
	else
	{
		newNode->next = cursor->next;
		cursor->next = newNode;
	}
}


template <typename T>
void CList<T>::remove()
{
	CNode<T>* old = cursor->next;
	if(old == cursor)
		cursor = NULL;
	else
		cursor->next = old->next;
	delete old;
}



