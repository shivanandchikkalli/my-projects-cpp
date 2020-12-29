#include<stdlib.h>
#include<iostream>

#include<stack>

#include "tree.h"

Node* currentPtr = NULL;
std::stack<Node*> st;

Tree::Tree()
{
    this->root = NULL;
    this->size = 0;
};

Tree::~Tree()
{
    // code deleting all the nodes of the tree
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

void Tree::Pre_Order_Insert(int value)
{
    if(size_of_tree() == 0)
    {
        Node* node = get_tree_node();
        node->element = value;

        this->root = node;
        this->size++;

        currentPtr = node;
        
        return;
    }

    if(value < currentPtr->element)
    {
        Node* node = get_tree_node();
        node->element = value;

        currentPtr->left = node;
        node->parent = currentPtr;

        this->size++;

        st.push(currentPtr);

        currentPtr = node;
    }
    else if(value > currentPtr->element && (st.empty() || value < st.top()->element))
    {
        Node* node = get_tree_node();
        node->element = value;

        currentPtr->right = node;
        node->parent = currentPtr;

        this->size++;

        currentPtr = node;
    }
    else
    {
        currentPtr = st.top();
        st.pop();
        Pre_Order_Insert(value);
    }
    
    
}

// This function is implemented using pre-order traversal
void Tree::printTree(Node* node) const
{
	Node* temp = node;

    std::stack<Node*> st;

    while(!st.empty() || temp != NULL)
    {
        if(temp != NULL)
        {
            std::cout << temp->element << " ";
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = st.top(); st.pop();
            temp = temp->right;
        }
        
    }
}


int Tree::count(Node* node) const
{
    if(node != NULL)
    {
        int x = count(node->left);
        int y = count(node->right);
        return x+y+1;
    }
    return 0;
}


int Tree::height(Node* node) const
{
    if(node != NULL)
    {
        int x = height(node->left);
        int y = height(node->right);
        if(x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}



