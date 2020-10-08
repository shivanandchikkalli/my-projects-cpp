#ifndef _DEQUE_H_
#define _DEQUE_H_

#include "doublylinkedlist.h"

template <typename T>
class Deque
{
	private:
		DList<T> List;
		int DequeSize;
	public:
		Deque();
		~Deque();
		bool empty() const;
		int size() const;
		void push_front(const T& t);
		void push_back(const T& t);
		void pop_front();
		void pop_back();
		const T& front();
		const T& back();
};


#endif
