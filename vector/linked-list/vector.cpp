#include <iostream>
#include "vector.h"

template <class T>
Vector<T>::Vector() : ListPtr(), count(0), capacity(0) {}

template <class T>
Vector<T>::~Vector()
{
	while(!ListPtr.empty())
	{
		ListPtr.removeFront();
	}
}

template<class T>
int Vector<T>::size() const
{
	return count;
}

template<class T>
bool Vector<T>::empty() const
{
	return count == 0;
}

template<class T>
const T& Vector<T>::at(int index) const
{
	if(index < count && index >= 0)
	{
		const DNode<T>* value = ListPtr.get_item_address(index);
		return ListPtr.get_element(value);

	}
	else
	{
		throw("Index out of bound");
	}
}

template<class T>
const T& Vector<T>::front() const
{
	return ListPtr.front();
}

template<class T>
const T& Vector<T>::back() const
{
	return ListPtr.back();
}

template<class T>
void Vector<T>::push_back(const T& element)
{
	ListPtr.addBack(element);
	count++;
}

template<class T>
const T& Vector<T>::pop_back()
{
	const T& returnValue = ListPtr.back();
	ListPtr.removeBack();
	count--;

	return returnValue;
}

template <class T>
void Vector<T>::insert(const T& element, int index)
{
	DNode<T>* node = ListPtr.get_item_address(index);

	ListPtr.add(node, element);

	count++;
}

template <class T>
const T& Vector<T>::operator[](int index)
{
	return at(index);
}



