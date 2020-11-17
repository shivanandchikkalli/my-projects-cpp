#include "list.h"

template <class T>
NodeList<T>::Iterator::Iterator(Node* u)
{
	v = u;
}

template <class T>
const T& NodeList<T>::Iterator::operator*() const
{
	return v->element;
}

template <class T>
bool NodeList<T>::Iterator::operator==(const NodeList<T>::Iterator& iterator) const
{
	return v == iterator.v;
}

template <class T>
bool NodeList<T>::Iterator::operator!=(const NodeList<T>::Iterator& iterator) const
{
	return v != iterator.v;
}

template <class T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator++()
{
	v = v->next;
	return *this;
}

template <class T>
typename NodeList<T>::Iterator& NodeList<T>::Iterator::operator--()
{
	v = v->prev;
	return *this;
}
