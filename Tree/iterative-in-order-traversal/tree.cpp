#include<stdlib.h>
#include<iostream>

#include<stack>

#include "tree.h"

Tree::Tree()
{
    this->root = NULL;
    this->size = 0;
};

Tree::~Tree()
{

};

Node* Tree::getRoot() const
{
    return this->root;
}

int Tree::size_of_tree() const
{
    return this->size;
}

Node* get_tree_node()
{
    Node* node = new Node;
    node->element = 0;
    node->left = NULL;
    node->parent = NULL;
    node->right = NULL;

    return node;
}

Node* Tree::addRoot(int value)
{
    Node* node = get_tree_node();
    node->element = value;

    this->root = node;

    return node;
}

Node* Tree::addLeft(Node* node, int value)
{
    Node* newNode = get_tree_node();
    newNode->element = value;

    newNode->parent = node;
    node->left = newNode;

    return newNode;
}

Node* Tree::addRight(Node* node, int value)
{
    Node* newNode = get_tree_node();
    newNode->element = value;

    newNode->parent = node;
    node->right = newNode;

    return newNode;
}

// This is in-order traversal
void Tree::printTree(Node* node) const
{
    Node* temp = node;

    std::stack<Node*> st;

    while(!st.empty() || temp != NULL)
    {
        if(temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = st.top(); st.pop();
            std::cout << temp->element << " ";
            temp = temp->right;
        }
        
    }
}






