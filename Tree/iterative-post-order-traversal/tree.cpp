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

// This is post-order traversal
void Tree::printTree(Node* node) const
{
    long long int temp;

    std::stack<long long int> st;

    while(!st.empty() || node != NULL)
    {
        if(node != NULL)
        {
            st.push((long long int)node);
            node = node->left;
        }
        else
        {
            temp = st.top();
            st.pop();
            
            if(temp > 0)
            {
                st.push(-temp);
                node = ((Node*)temp)->right;
            }
            else
            {
                std::cout << ((Node*)(-1 * temp))->element << " ";
                node = NULL;
            }
        }
        
    }
}






