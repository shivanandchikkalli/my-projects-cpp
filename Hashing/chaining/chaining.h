#ifndef _H_Chaining_
#define _H_Chaining_

typedef struct Node
{
    int element;
    struct Node* next;
}Node;

class Chaining
{
    private:
        Node** array;
    public:
        Chaining();
        ~Chaining();

        void Insert(int value);
        void Delete(int value);

        bool Search(int value);

        void Print();
};

#endif