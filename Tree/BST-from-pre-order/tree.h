#ifndef _H_TREE_
#define _H_TREE_

typedef struct Node
{
    int element;
    Node* parent;
    Node* left;
    Node* right;
}Node;

class Tree
{
    private:
        Node* root;
        int size;
    public:
        Tree();
        ~Tree();
        Node* getRoot() const;
        int size_of_tree() const;

        void Pre_Order_Insert(int value);

        void printTree(Node* node) const;
        int count(Node* node) const;
        int height(Node* node) const;
};


#endif