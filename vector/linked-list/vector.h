#ifndef VECTOR_H_
#define VECTOR_H_

#include "doublylinkedlist.h"

template <class T>
class Vector
{
	public:
		Vector();
		~Vector();
		int size() const;
		bool empty() const;
		const T& at(int index) const;
		const T& front() const;
		const T& back() const;
		void push_back(const T& element);
		const T& pop_back();
		void insert(const T& element, int index);

		const T& operator[](int index);
	private:
		DList<T> ListPtr;
		int count;
		int capacity;
};

#endif
