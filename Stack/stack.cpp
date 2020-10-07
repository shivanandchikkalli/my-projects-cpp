#include "singlylinkedlist.h"
#include "stack.h"


template <typename T>
Stack<T>::Stack()
{
	Stacksize = 0;
}


template <typename T>
Stack<T>::~Stack()
{
	while(!List.empty())
	{
		List.removeFront();
	}
}


template <typename T>
bool Stack<T>::empty() const
{
	return Stacksize == 0;
}

template <typename T>
int Stack<T>::size() const
{
	return Stacksize;
}

template <typename T>
void Stack<T>::push(const T& t)
{
	Stacksize++;
	List.addFront(t);
}

template <typename T>
void Stack<T>::pop()
{
	Stacksize--;
	List.removeFront();
}

template <typename T>
const T& Stack<T>::top() const
{
	return List.front();
}
