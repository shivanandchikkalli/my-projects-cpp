#include<iostream>

#include "dll.h"


template <typename T>
DList<T>::DList()
{	
	header = new DNode<T>;
	trailer = new DNode<T>;
	header->next = trailer;
	trailer->prev = header;	
}


template <typename T>
DList<T>::~DList()
{
	while(!empty())
	{
		removeFront();
	}
	delete header;
	delete trailer;
}


template <typename T>
bool DList<T>::empty() const
{
	return header->next == trailer;
}


template <typename T>
const T& DList<T>::front()
{
	return header->next->element;
}


template <typename T>
const T& DList<T>::back()
{
	return trailer->prev->element;
}

template <typename T>
void DList<T>::addFront(const T& t)
{
	add(header->next, t);
}


template <typename T>
void DList<T>::addBack(const T& t)
{
	add(trailer, t);
}


template <typename T>
void DList<T>::removeFront()
{
	remove(header->next);
}


template <typename T>
void DList<T>::removeBack()
{
	remove(trailer->prev);	
}


template <typename T>
void DList<T>::add(DNode<T>* node, const T& t)
{
	DNode<T>* newNode = new DNode<T>;
	newNode->element = t;
	
	newNode->next = node;
	newNode->prev = node->prev;
	
	node->prev->next = newNode;
	node->prev = newNode;
}


template <typename T>
void DList<T>::remove(DNode<T>* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	
	delete node;
}


template <typename T>
void DList<T>::register_print_function(void (*print_dll)(const T& t))
{
	this->print_dll = print_dll;
}


template <typename T>
void DList<T>::print_list_items() const
{
	DNode<T>* cursor = header->next;
	while(cursor != trailer)
	{
		print_dll(cursor->element);
		cursor = cursor->next;
	}
}



