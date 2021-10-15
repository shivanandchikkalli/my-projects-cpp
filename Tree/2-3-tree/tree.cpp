#include<stdlib.h>
#include<iostream>

#include<stack>

#include "tree.h"

Tree::Tree()
{
    this->root = NULL;
    this->size = 0;
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
    node->element1 = NULL;
    node->element2 = NULL;
    node->parent = NULL;
    node->left = NULL;
    node->middle = NULL;
    node->right = NULL;

    return node;
}

void Tree::Insert(Node* node, int value)
{
    if(this->root == NULL)
    {
        Node* newNode = get_tree_node();
        newNode->element1 = value;

        this->root = newNode;

        this->size++;

        return;
    }

    if(node)
    {
        if(node->element2 == NULL)
        {
            if(value < node->element1 && node->left == NULL && node->middle == NULL)
            {
                node->element2 = node->element1;
                node->element1 = value;
            }
            else if(value > node->element1 && node->left == NULL && node->middle == NULL)
            {
                node->element2 = value;
            }
            else if(value < node->element1 && node->left != NULL)
            {
                Insert(node->left, value);
            }
            else if(value > node->element1 && node->middle != NULL)
            {
                Insert(node->middle, value);
            }
        }
        else
        {
            if(value < node->element1  && node->left != NULL && node->middle != NULL)
                Insert(node->left, value);
            else if(value > node->element1 && value < node->element2  && node->left != NULL && node->middle != NULL)
                Insert(node->middle, value);
            else if(value > node->element2 && node->right != NULL)
                Insert(node->right, value);
            else if(value < node->element1)
            {
                Node* right = get_tree_node();
                Node* nParent = node->parent;
                if(nParent == NULL)
                {
                    Node* parent = get_tree_node();
                    this->root = parent;

                    parent->left = node;
                    node->parent = parent;

                    parent->middle = right;
                    right->parent = parent;

                    parent->element1 = node->element1;
                    right->element1 = node->element2;
                    node->element1 = value;                    
                }
                else if(nParent->element2 == NULL)
                {
                    nParent->right = nParent->middle;

                    right->parent = nParent;
                    nParent->middle = right;

                    right->element1 = node->element2;
                    Insert(nParent, node->element1);
                    node->element1 = value;
                }
                else
                {
                    
                }
                
            }
            else if(value > node->element1 && value < node->element2)
            {
                Node* right = get_tree_node();

                Node* nParent = node->parent;

                if(nParent == NULL)
                {
                    Node* parent = get_tree_node();
                    this->root = parent;

                    parent->left = node;
                    node->parent = parent;

                    parent->middle = right;
                    right->parent = parent;

                    parent->element1 = value;
                    right->element1 = node->element2;
                    node->element2 = NULL;
                }
                else if(nParent->element2 == NULL)
                {
                    nParent->right = right;
                    right->parent = nParent;

                    right->element2 = node->element2;
                    node->element2 = NULL;
                    Insert(nParent, value);
                }
                else
                {
                    
                }
                
                
            }
            else if(value > node->element2)
            {
                Node* right = get_tree_node();

                Node* nParent = node->parent;

                if(nParent == NULL)
                {
                    Node* parent = get_tree_node();
                    this->root = parent;

                    parent->left = node;
                    node->parent = parent;

                    parent->middle = right;
                    right->parent = parent;

                    parent->element1 = node->element2;
                    node->element2 = NULL;
                    right->element1 = value;

                }
                else if(nParent->element2 == NULL)
                {
                    nParent->right = right;
                    right->parent = nParent;
                    
                    right->element1 = value;
                    Insert(nParent, node->element2);
                    node->element2 = NULL;
                }
                else
                {
                    right->element1 = value;
                    
                }
                

            }
        }
        
    }


}

// int Height(Node *p) {
//     int x;
//     int y;
//     if (p == nullptr){
//         return 0;
//     }
//     x = Height(p->left);
//     y = Height(p->right);
//     return x > y ? x + 1 : y + 1;
// }

// const Node* Tree::Search(int value) const
// {
//     Node* temp = this->root;

//     while(temp != NULL)
//     {
//         if(value == temp->element[0])
//             return temp;
//         else if(value < temp->element[0])
//             temp = temp->left;
//         else
//             temp = temp->right;
//     }
//     return NULL;
// }

// const Node* Tree::RSearch(Node* node, int value) const
// {
//     if(node != NULL)
//     {
//         if(value == node->element[0])
//             return node;
//         else if(value < node->element[0])
//             return RSearch(node->left, value);
//         else
//             return RSearch(node->right, value);
//     }
//     return NULL;
// }

// This function is implemented using in-order traversal
// void Tree::printTree(Node* node) const
// {
// 	Node* temp = node;

//     std::stack<Node*> st;

//     while(!st.empty() || temp != NULL)
//     {
//         if(temp != NULL)
//         {
//             st.push(temp);
//             temp = temp->left;
//         }
//         else
//         {
//             temp = st.top(); st.pop();
//             std::cout << temp->element << " ";
//             temp = temp->right;
//         }
        
//     }
// }


// int Tree::count(Node* node) const
// {
//     if(node != NULL)
//     {
//         int x = count(node->left);
//         int y = count(node->right);
//         return x+y+1;
//     }
//     return 0;
// }


// int Tree::height(Node* node) const
// {
//     if(node != NULL)
//     {
//         int x = height(node->left);
//         int y = height(node->right);
//         if(x > y)
//             return x + 1;
//         else
//             return y + 1;
//     }
//     return 0;
// }

// // This is post-order traversal
// void Tree::PostOrderDelete(Node* node)
// {
//     long long int temp;

//     std::stack<long long int> st;

//     while(!st.empty() || node != NULL)
//     {
//         if(node != NULL)
//         {
//             st.push((long long int)node);
//             node = node->left;
//         }
//         else
//         {
//             temp = st.top();
//             st.pop();
            
//             if(temp > 0)
//             {
//                 st.push(-temp);
//                 node = ((Node*)temp)->right;
//             }
//             else
//             {
//                 Delete_Node(((Node*)(-1 * temp)));
//                 node = NULL;
//             }
//         }
        
//     }
// }

Tree::~Tree()
{
    // code deleting all the nodes of the tree
    //PostOrderDelete(this->root);
};

