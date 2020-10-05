#ifndef _SLL_H
#define _SLL_H

template <typename E>
class SNode;

template <typename E>
class SList
{
	public:
		SList();
		~SList();
		bool empty() const;
		const E& front() const;
		void addFront(const E& e);
		void removeFront();
	private:
		SNode<E>* head;
};


template <typename E>
class SNode
{
	private:
		E element;
		SNode<E>* next;
	friend class SList<E>;
};

#endif
