#include<stdlib.h>
#include<iostream>

#include "tree.h"

Tree::Tree()
{
    this->root = NULL;
    this->size = 0;
};

Tree::~Tree()
{

};

const Node* Tree::getRoot() const
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

void Tree::printTree(const Node* node) const
{
	if(node != NULL)
	{
		printTree(node->left);
		std::cout << node->element << " " << std::endl;
		printTree(node->right);
	}
}



