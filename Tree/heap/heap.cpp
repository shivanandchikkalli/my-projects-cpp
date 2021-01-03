#include<iostream>

#include "heap.h"

Heap::Heap()
{
    this->array = NULL;
    this->heap_size = 0;
}

void Heap::Initialize(int size)
{
    int* array = new int[size+1];
    this->array_size = size;
    this->array = array;
}

int Heap::get_heap_size()
{
    return this->heap_size;
}


void Heap::Insert(int value)
{
    if(this->array)
    {
        int lastIndex = get_heap_size() + 1;
        while(lastIndex > 1)
        {
            int pIndex = lastIndex / 2;
            if(this->array[pIndex] < value)
            {
                this->array[lastIndex] = this->array[pIndex];
                lastIndex = pIndex;
            }
            else
                break;
            
        }
        this->array[lastIndex] = value;

        this->heap_size++;
    }
}


void Heap::Delete()
{
    if(this->array)
    {
        int size = get_heap_size();
        int deletedItem = this->array[1];
        this->array[1] = this->array[size];
        int i = 1 , j = 2 * i;

        while(i < size - 1)
        {
            if(j + 1 < size && this->array[j] < this->array[j + 1])
                j = j + 1;
            if(j < size && this->array[i] < this->array[j])
            {
                int temp = this->array[i];
                this->array[i] = this->array[j];
                this->array[j] = temp;
                i = j;
                j = 2 * j;
            }
            else
                break;
            
        }

        this->array[size] = deletedItem; // for Heap Sort

        this->heap_size--;
    }
}

void Heap::Print()
{
    std::cout << "Heap Elements " << std::endl;
    for(int i = 0 ; i < get_heap_size() ; i++)
    {
        std::cout << this->array[i+1] << " ";
    }
}


void Heap::HeapSort()
{
    int size = get_heap_size();
    for(int i = 0 ; i < size ; i++)
    {
        Delete();
    }
    std::cout << "Heap Sorted" << std::endl;
    for(int i = 0 ; i < this->array_size ; i++)
    {
        std::cout << this->array[i+1] << " ";
    }
}

Heap::~Heap()
{
    
}