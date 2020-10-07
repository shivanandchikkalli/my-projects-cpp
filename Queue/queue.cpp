#include "circularlinkedlist.h"
#include "queue.h"


template <typename T>
Queue<T>::Queue() : queueSize(0), List() {}

template <typename T>
Queue<T>::~Queue()
{
	while(List.empty())
	{
		List.remove();
	}
}

template <typename T>
bool Queue<T>::empty() const
{
	return queueSize == 0;
}

template <typename T>
int Queue<T>::size() const
{
	return queueSize;
}

template <typename T>
void Queue<T>::enqueue(const T& t)
{
	queueSize++;
	List.add(t);
	List.advance();
}

template <typename T>
void Queue<T>::dequeue()
{
	queueSize--;
	List.remove();
}

template <typename T>
const T& Queue<T>::front()
{
	return List.front();
}
