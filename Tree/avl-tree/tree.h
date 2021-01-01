#ifndef _H_TREE_
#define _H_TREE_

// This is just a simple tree creation code and display the created tree using inorder traversal method
// Contains only add methods (left and right)

typedef struct Node
{
    int element;
    Node* parent;
    Node* left;
    int height;
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

        void Insert(int value);
        Node* RInsert(Node* node, int value);

        void Delete(int value);
        void Delete_Node(Node* node);

        const Node* Search(int value) const;
        const Node* RSearch(Node* node, int value) const;

        Node* Get_inorder_predecessor(Node* node);
        Node* Get_inorder_successor(Node* node);

        Node* LLRotation(Node* node);
        Node* LRRotation(Node* node);
        Node* RRRotation(Node* node);
        Node* RLRotation(Node* node);

        void printTree(Node* node) const;
        int count(Node* node) const;
        int height(Node* node) const;
};


#endif