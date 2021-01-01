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

int NodeHeight(Node* node)
{
    int x = node && node->left ? node->left->height : 0;
    int y = node && node->right ? node->right->height : 0;

    return x > y ? x + 1 : y + 1;
}

int BalanceFactor(Node* node)
{
    int hl = node && node->left ? node->left->height : 0;
    int hr = node && node->right ? node->right->height : 0;

    return hl - hr;
}

Node* Tree::LLRotation(Node* node)
{
    if(node != NULL)
    {
        std::cout << "LL Rotation around : " << node->element << std::endl;
        Node* nodeParent = node->parent;
        Node* lnode = node->left;
        Node* lrnode = lnode->right;

        lnode->right = node;
        node->parent = lnode;
        node->left = lrnode;

        if(nodeParent == NULL)
        {
            lnode->parent = NULL;
            this->root = lnode;
        }
        else
        {
            if(node == nodeParent->left)
                nodeParent->left = lnode;
            else
                nodeParent->right = lnode;
            lnode->parent = nodeParent;
        }

        node->height = NodeHeight(node);
        lnode->height = NodeHeight(lnode);
        
        return lnode;
    }
    return node;
}

Node* Tree::LRRotation(Node* node)
{
    if(node != NULL)
    {
        std::cout << "LR Rotation around : " << node->element << std::endl;
        Node* lnode = node->left;
        Node* lrnode  = lnode->right;
        Node* lrlnode = lrnode->left;
        Node* lrrnode = lrnode->right;

        Node* nodeParent = node->parent;

        lrnode->left = lnode;
        lnode->parent = lrnode;
        lrnode->right = node;
        node->parent = lrnode;

        lnode->right = lrlnode;
        if(lrlnode) lrlnode->parent = lnode;
        node->left = lrrnode;
        if(lrrnode) lrrnode->parent = node;

        if(nodeParent == NULL)
        {
            lrnode->parent = NULL;
            this->root = lrnode;
        }
        else
        {
            if(node == nodeParent->left)
                nodeParent->left = lrnode;
            else
                nodeParent->right = lrnode;
            lrnode->parent = nodeParent;
        }

        node->height = NodeHeight(node);
        lrnode->height = NodeHeight(lrnode);
        lnode->height = NodeHeight(lnode);

        return lrnode;

    }
    return node;
}

Node* Tree::RRRotation(Node* node)
{
    if(node)
    {
        std::cout << "RR Rotation around : " << node->element << std::endl;
        Node* nodeParent = node->parent;
        Node* rnode = node->right;
        Node* rlnode = rnode->left;

        rnode->left = node;
        node->parent = rnode;
        node->right = rlnode;
        if(rlnode) rlnode->parent = node;       

        if(nodeParent == NULL)
        {
            rnode->parent = NULL;
            this->root = rnode;
        }
        else
        {
            if(node == nodeParent->left)
                nodeParent->left = rnode;
            else
                nodeParent->right = rnode;
            rnode->parent = nodeParent;
        }

        node->height = NodeHeight(node);
        rnode->height = NodeHeight(rnode);         

        return rnode;

    }
    return node;
}

Node* Tree::RLRotation(Node* node)
{
    if(node)
    {
        std::cout << "RL Rotation around : " << node->element << std::endl;
        Node* rnode = node->right;
        Node* rlnode = rnode->left;
        Node* rllnode = rlnode->left;
        Node* rlrnode = rlnode->right;
        Node* nodeParent = node->parent;

        rlnode->left = node;
        node->parent = rlnode;
        rlnode->right = rnode;
        rnode->parent = rlnode;

        node->right = rllnode;
        rnode->left = rlrnode;
        if(rllnode) rllnode->parent = node;
        if(rlrnode) rlrnode->parent = rnode;

        if(nodeParent == NULL)
        {
            rlnode->parent = NULL;
            this->root = rlnode;
        }
        else
        {
            if(node == nodeParent->left)
                nodeParent->left = rlnode;
            else
                nodeParent->right = rlnode;
            rlnode->parent = nodeParent;
        }

        node->height = NodeHeight(node);
        rlnode->height = NodeHeight(rlnode);
        rnode->height = NodeHeight(rnode);

        return rlnode;
    }
    return node;
}

Node* Tree::RInsert(Node* node, int value)
{
    if(node == NULL)
    {
        Node* node = get_tree_node();
        node->element = value;
        node->height = 1;

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

    node->height = NodeHeight(node);

    int nodeBf = BalanceFactor(node);
    int nodelBf = BalanceFactor(node->left);
    int noderBf = BalanceFactor(node->right);

    if(nodeBf == 2 && nodelBf == 1)
        return LLRotation(node);
    else if(nodeBf == 2 && nodelBf == -1)
        return LRRotation(node);
    else if(nodeBf == -2 && noderBf == 1)
        return RLRotation(node);
    else if(nodeBf == -2 && noderBf == -1)
        return RRRotation(node);
    
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

void Tree::BalanceTreePostDeletion(Node* node)
{
    if(node)
    {
        node->height = NodeHeight(node);

        int nodeBf = BalanceFactor(node);
        int nodelBf = BalanceFactor(node->left);
        int noderBf = BalanceFactor(node->right);

        if(nodeBf == 2 && nodelBf == 1)
            node = LLRotation(node);
        else if(nodeBf == 2 && nodelBf == -1)
            node = LRRotation(node);
        else if(nodeBf == 2 && nodelBf == 0)
            node = LLRotation(node);            
        else if(nodeBf == -2 && noderBf == 1)
            node = RLRotation(node);
        else if(nodeBf == -2 && noderBf == -1)
            node = RRRotation(node);
        else if(nodeBf == -2 && noderBf == 0)
            node = RRRotation(node);      

        BalanceTreePostDeletion(node->parent);
    }
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
            BalanceTreePostDeletion(node->parent);
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

// This is post-order traversal
void Tree::PostOrderDelete(Node* node)
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
                Delete_Node(((Node*)(-1 * temp)));
                node = NULL;
            }
        }
        
    }
}

Tree::~Tree()
{
    // code deleting all the nodes of the tree
    PostOrderDelete(this->root);
};

