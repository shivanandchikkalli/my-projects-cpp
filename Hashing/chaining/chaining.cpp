#include<iostream>

#include "chaining.h"

Chaining::Chaining()
{
    this->array = new Node*[10];
    for(int i = 0 ; i < 10 ; i++)
    {
    	this->array[i] = NULL;
    }
}


Chaining::~Chaining()
{
    for(int i = 0 ; i < 10 ; i++)
    {
        Node* node = this->array[i];
        while(node)
        {
            Node* temp = node;
            node = node->next;
            delete temp;
        }
        this->array[i] = NULL;
    }
    delete[] this->array;
}

Node* get_node(int value)
{
    Node* newNode = new Node;
    newNode->element = value;
    newNode->next = NULL;

    return newNode;
}

int get_index(int value)
{
    return value % 10;
}

void Chaining::Insert(int value)
{
    Node* node = get_node(value);
    int index = get_index(value);

    Node* prev = this->array[index];
    if(prev)
    {
        if(prev->element >= value)
        {
            node->next = prev;
            this->array[index] = node;
        }
        else
        {
            Node* temp = prev->next;
            while(temp && temp->element < value)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = node;
            node->next = temp;
        }
    }
    else
    {
        this->array[index] = node;
    }
    
}

void Chaining::Print()
{
    std::cout << std::endl << "---------------------------" << std::endl;
    for(int i = 0 ; i < 10 ; i++)
    {
        Node* node = this->array[i];
        while(node)
        {
            std::cout << node->element << " ";
            node = node->next;
        }
        std::cout << "-----" << std::endl;
    }
    std::cout << "---------------------------" << std::endl << std::endl;
}

void Chaining::Delete(int value)
{
    int index = get_index(value);
    Node* prev = this->array[index];
    if(prev)
    {
        Node* temp = prev->next;
        if(prev->element == value)
        {
            this->array[index] = temp;
            delete prev;
            return;
        }
        else
        {
            while(temp)
            {
                if(temp->element == value)
                {
                    prev->next = temp->next;
                    delete temp;
                    return;
                }
                if(temp->element < value)
                {
                    prev = temp;
                    temp = temp->next;
                }
                else
                    return;
            }
        }
    }    
}

bool Chaining::Search(int value)
{
    int index = get_index(value);
    Node* node = this->array[index];
    while(node)
    {
        if(node->element > value)
            return false;
        else if(node->element == value)
            return true;
        else
            node = node->next;       
    }
    return false;
}