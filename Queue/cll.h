#ifndef _CLL_H_
#define _CLL_H_

template <typename T>
class CList;

template <typename T>
class CNode
{
	private:
		T element;
		CNode<T>* next;
	
	friend class CList<T>;
};

template <typename T>
class CList
{
	private:
		CNode<T>* cursor;
	public:
		CList();
		~CList();
		bool empty();
		const T& front() const;
		const T& back() const;
		void advance();
		void add(const T& t);
		void remove();
};


#endif
