#include "list.h"

template <class T>
NodeList<T>::NodeList()
{
	n = 0;
	header = new Node();
	trailer = new Node();
	header->next = trailer;
	trailer->prev = header;
}

template <class T>
NodeList<T>::~NodeList()
{
	while(!empty())
	{
		removeFront();
	}
	delete header;
	delete trailer;
}

template <class T>
int NodeList<T>::size() const
{
	return n;
}

template <class T>
bool NodeList<T>::empty() const
{
	return n == 0;
}

template <class T>
typename NodeList<T>::Iterator NodeList<T>::begin() const
{
	return Iterator(header->next);
}

template <class T>
typename NodeList<T>::Iterator NodeList<T>::end() const
{
	return Iterator(trailer);
}

template <class T>
void NodeList<T>::insertFront(const T& element)
{
	insert(begin(), element);
}

template <class T>
void NodeList<T>::insertBack(const T& element)
{
	insert(end(), element);
}

template <class T>
void NodeList<T>::insert(const Iterator& iterator, const T& element)
{
	Node* newNode = new Node();
	newNode->element = element;
	newNode->prev = iterator.v->prev;
	newNode->next = iterator.v;

	iterator.v->prev->next = newNode;
	iterator.v->prev = newNode;

	n++;
}

template <class T>
void NodeList<T>::removeFront()
{
	remove(begin());
}

template <class T>
void NodeList<T>::removeBack()
{
	remove(--end());
}

template <class T>
void NodeList<T>::remove(const Iterator& iterator)
{
	iterator.v->next->prev = iterator.v->prev;
	iterator.v->prev->next = iterator.v->next;

	delete iterator.v;
	n--;
}
