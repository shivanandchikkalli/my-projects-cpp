#ifndef _STACK_H_
#define _STACK_H_

#include "singlylinkedlist.h"


template <typename T>
class Stack
{
	private:
		SList<T> List;
		int Stacksize;
	public:
		Stack();
		~Stack();
		bool empty() const;
		int size() const;
		void push(const T& t);
		void pop();
		const T& top() const;
};



#endif
