#include "list.h"

NodeList::NodeList()
{
	n = 0;
	header = new Node();
	trailer = new Node();
	header->next = trailer;
	trailer->prev = header;
}

NodeList::~NodeList()
{
	while(!empty())
	{
		removeFront();
	}
	delete header;
	delete trailer;
}

int NodeList::size() const
{
	return n;
}

bool NodeList::empty() const
{
	return n == 0;
}

NodeList::Iterator NodeList::begin() const
{
	return Iterator(header->next);
}

NodeList::Iterator NodeList::end() const
{
	return Iterator(trailer);
}

void NodeList::insertFront(const Elem& element)
{
	insert(begin(), element);
}

void NodeList::insertBack(const Elem& element)
{
	insert(end(), element);
}

void NodeList::insert(const Iterator& iterator, const Elem& element)
{
	Node* newNode = new Node();
	newNode->element = element;
	newNode->prev = iterator.v->prev;
	newNode->next = iterator.v;

	iterator.v->prev->next = newNode;
	iterator.v->prev = newNode;

	n++;
}

void NodeList::removeFront()
{
	remove(begin());
}

void NodeList::removeBack()
{
	remove(--end());
}

void NodeList::remove(const Iterator& iterator)
{
	iterator.v->next->prev = iterator.v->prev;
	iterator.v->prev->next = iterator.v->next;

	delete iterator.v;
	n--;
}
