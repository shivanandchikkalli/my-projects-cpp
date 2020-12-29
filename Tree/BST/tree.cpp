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

Node* Tree::Get_inorder_predecessor(Node* node)
{
    if(node != NULL)
    {
        Node* temp = node->left;

        while(temp != NULL)
        {
            if(temp->right != NULL) temp = temp->right;
            else
                break;   
        }
        return temp;
    }
    return node;
}

Node* Tree::Get_inorder_successor(Node* node)
{
    if(node != NULL)
    {
        Node* temp = node->right;

        while(temp != NULL)
        {
            if(temp->left != NULL) temp = temp->left;
            else
                break;   
        }
        return temp;
    }
    return node;
}

void Tree::Insert(int value)
{
    if(size_of_tree() == 0)
    {
        Node* node = get_tree_node();
        node->element = value;

        this->root = node;

        this->size++;

        return;
    }

    Node* temp = this->root;
    Node* parent = NULL;

    while(temp != NULL)
    {
        if(value == temp->element) // No duplicates allowed in BST
            return;
        else if(value < temp->element)
        {
            parent = temp;
            temp = temp->left;
        }
        else
        {
            parent = temp;
            temp = temp->right;
        }
    }

    Node* node = get_tree_node();
    node->element = value;
    node->parent = parent;

    if(value < parent->element) parent->left = node;
    else if(value > parent->element) parent->right = node;

    this->size++;
}

Node* Tree::RInsert(Node* node, int value)
{
    if(node == NULL)
    {
        Node* node = get_tree_node();
        node->element = value;

        if(size_of_tree() == 0) this->root = node;

        this->size++;

        return node;
    }

    if(value < node->element)
    {
        Node* lNode = RInsert(node->left, value);
        node->left = lNode;
        lNode->parent = node;
    }
    else if(value > node->element)
    {
        Node* rNode = RInsert(node->right, value);
        node->right = rNode;
        rNode->parent = node;
    }
    
    return node;
}

int Height(Node *p) {
    int x;
    int y;
    if (p == nullptr){
        return 0;
    }
    x = Height(p->left);
    y = Height(p->right);
    return x > y ? x + 1 : y + 1;
}

void Tree::Delete(int value)
{
    Node* temp = this->root;

    while(temp != NULL && temp->element != value)
    {
        if(value < temp->element)
            temp = temp->left;
        else if(value > temp->element)
            temp = temp->right;
    }
    Delete_Node(temp);
}

void Tree::Delete_Node(Node* node)
{
    if(node != NULL)
    {
        //Case-1 if node is external/leaf node
        if(node->left == NULL && node->right == NULL)
        {
            if(node->parent != NULL)
            {
                if(node == node->parent->left)
                    node->parent->left = NULL;
                else
                    node->parent->right = NULL;
            }
            else
            {
                this->root = NULL;
            }
            delete node;
        }
        //Case-2 if node has at-least one child
        else
        {
            Node* replacer;
            if(Height(node->left) > Height(node->right))
                replacer = Get_inorder_predecessor(node);
            else
                replacer = Get_inorder_successor(node);

            if(replacer != NULL)
            {
                node->element = replacer->element;
                Delete_Node(replacer);
            }
        }
    }
}

const Node* Tree::Search(int value) const
{
    Node* temp = this->root;

    while(temp != NULL)
    {
        if(value == temp->element)
            return temp;
        else if(value < temp->element)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return NULL;
}

const Node* Tree::RSearch(Node* node, int value) const
{
    if(node != NULL)
    {
        if(value == node->element)
            return node;
        else if(value < node->element)
            return RSearch(node->left, value);
        else
            return RSearch(node->right, value);
    }
    return NULL;
}

// This function is implemented using in-order traversal
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



