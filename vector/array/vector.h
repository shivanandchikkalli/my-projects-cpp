#ifndef _VECTOR_CLASS_H_
#define _VECTOR_CLASS_H_

template <class T>
class Vector
{
	public:
		Vector();
		~Vector();
		int size() const;
		bool empty() const;
		void resize(int n);
		void reserve(int n);
		const T& at(int index) const;
		const T& front() const;
		const T& back() const;
		void push_back(const T& element);
		const T& pop_back();
		void insert(const T& element, int index);

		const T& operator[](int index);
	private:
		T* ArrayPtr;
		int count;
		int capacity;
};

#endif
