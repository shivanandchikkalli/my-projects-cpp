#include "list.h"


NodeList::Iterator::Iterator(Node* u)
{
	v = u;
}

const Elem& NodeList::Iterator::operator*() const
{
	return v->element;
}

bool NodeList::Iterator::operator==(const Iterator& iterator) const
{
	return v == iterator.v;
}

bool NodeList::Iterator::operator!=(const Iterator& iterator) const
{
	return v != iterator.v;
}

NodeList::Iterator& NodeList::Iterator::operator++()
{
	v = v->next;
	return *this;
}

NodeList::Iterator& NodeList::Iterator::operator--()
{
	v = v->prev;
	return *this;
}
