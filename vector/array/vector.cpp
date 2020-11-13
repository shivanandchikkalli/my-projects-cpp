#include <iostream>
#include "vector.h"

template <class T>
Vector<T>::Vector() : ArrayPtr(NULL), count(0), capacity(0) {}

template <class T>
Vector<T>::~Vector()
{
	delete []ArrayPtr;

	ArrayPtr = NULL;
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
		return ArrayPtr[index];
	}
	else
	{
		throw("Index out of bound");
	}
}

template<class T>
void Vector<T>::resize(int n)
{
	if(capacity >= n)
	{
		std::cout << "" << std::endl;
	}
	T* newArrayPtr = new T[n];
	for(int i = 0 ; i < count ; i++)
	{
		newArrayPtr[i] = ArrayPtr[i];
	}
	if(ArrayPtr != NULL) delete []ArrayPtr;
	ArrayPtr = newArrayPtr;
	capacity = n;
}

template<class T>
void Vector<T>::reserve(int n)
{
	if(n >= 0 and count == 0)
	{
		ArrayPtr = new T[n];
		capacity = n;
	}
	else
	{
		resize(n);
	}
}


template<class T>
const T& Vector<T>::front() const
{
	return at(0);
}

template<class T>
const T& Vector<T>::back() const
{
	return at(count-1);
}

template<class T>
void Vector<T>::push_back(const T& element)
{
	insert(element, count);
}

template<class T>
const T& Vector<T>::pop_back()
{
	T& returnValue = ArrayPtr[count];
	ArrayPtr[count] = (int)NULL;
	count--;

	return returnValue;
}

template <class T>
void Vector<T>::insert(const T& element, int index)
{
	if(count >= capacity)
	{
		reserve(std::max(1, 2 * capacity));
	}
	for(int i = count - 1; i >= index; i--)
	{
		ArrayPtr[i+1] = ArrayPtr[i];
	}
	ArrayPtr[index] = element;
	count++;
}

template <class T>
const T& Vector<T>::operator[](int index)
{
	return at(index);
}



