#include "deque.h"
#include "doublylinkedlist.h"


template <typename T>
Deque<T>::Deque() : DequeSize(0), List() {}


template <typename T>
Deque<T>::~Deque()
{
	while(!List.empty())
	{
		List.removeFront();
	}
}

template <typename T>
bool Deque<T>::empty() const
{
	return DequeSize == 0;
}


template <typename T>
int Deque<T>::size() const
{
	return DequeSize;
}


template <typename T>
void Deque<T>::push_front(const T& t)
{
	List.addFront(t);
	DequeSize++;
}

template <typename T>
void Deque<T>::push_back(const T& t)
{
	List.addBack(t);
	DequeSize++;
}

template <typename T>
void Deque<T>::pop_front()
{
	List.removeFront();
	DequeSize--;
}

template <typename T>
void Deque<T>::pop_back()
{
	List.removeBack();
	DequeSize--;
}


template <typename T>
const T& Deque<T>::front()
{
	return List.front();
}


template <typename T>
const T& Deque<T>::back()
{
	return List.back();
}




