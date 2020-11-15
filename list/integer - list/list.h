#ifndef LIST_H_
#define LIST_H_

typedef int Elem;
class NodeList
{
	private:
		struct Node
		{
			Elem element;
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
				const Elem& operator*() const;
				bool operator==(const Iterator& iterator) const;
				bool operator!=(const Iterator& iterator) const;
				Iterator& operator++();
				Iterator& operator--();

				friend class NodeList;
		};
	public:
		NodeList();
		~NodeList();
		int size() const;
		bool empty() const;
		Iterator begin() const;
		Iterator end() const;
		void insertFront(const Elem& element);
		void insertBack(const Elem& element);
		void insert(const Iterator& iterator, const Elem& element);
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
