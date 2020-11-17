#ifndef LIST_H_
#define LIST_H_

template <class T>
class NodeList
{
	private:
		struct Node
		{
			T element;
			Node* next;
			Node* prev;
		};
	public:
		class Iterator
		{
			private:
				Node* v;
				Iterator(Node* u);
			public:
				const T& operator*() const;
				bool operator==(const Iterator& iterator) const;
				bool operator!=(const Iterator& iterator) const;
				Iterator& operator++();
				Iterator& operator--();

				friend class NodeList<T>;
		};
	public:
		NodeList();
		~NodeList();
		int size() const;
		bool empty() const;
		Iterator begin() const;
		Iterator end() const;
		void insertFront(const T& element);
		void insertBack(const T& element);
		void insert(const Iterator& iterator, const T& element);
		void removeFront();
		void removeBack();
		void remove(const Iterator& iterator);
		//---copy/move constructor assignment operator
	private:
		int n;
		Node* header;
		Node* trailer;
};



#endif
