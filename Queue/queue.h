#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "circularlinkedlist.h"

template <typename T>
class Queue
{
	private:
		CList<T> List;
		int queueSize;
	public:
		Queue();
		~Queue();
		bool empty() const;
		int size() const;
		void enqueue(const T& t);
		void dequeue();
		const T& front();
};


#endif
