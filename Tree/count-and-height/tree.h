#ifndef _H_TREE_
#define _H_TREE_

// This is just a simple tree creation code and display the created tree using inorder traversal method
// Contains only add methods (left and right)

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
        Node* addRoot(int value);
        Node* addLeft(Node* node, int value);
        Node* addRight(Node* node, int value);
        void printTree(Node* node) const;
        int count(Node* node) const;
        int height(Node* node) const;
};


#endif