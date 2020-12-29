#include<stdlib.h>
#include<iostream>

#include<queue>

#include "tree.h"

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

// This function is implemented using level ordering
void Tree::printTree(Node* node) const
{
	Node* temp = node;
    std::queue<Node*> queue;

    std::cout << temp->element << " ";

    queue.push(temp->left);
    queue.push(temp->right);

    while(!queue.empty())
    {
        temp = queue.front();
        queue.pop();

        if(temp->left != NULL) queue.push(temp->left);
        if(temp->right != NULL) queue.push(temp->right);

        std::cout << temp->element << " ";
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



