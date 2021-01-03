#include<iostream>

#include "heap.h"

int main()
{
    Heap heap;

    int userInput = 0;
    int heapSize = 0;

    std::cout << "size of heap : " << std::endl;
    std::cin >> heapSize;

    heap.Initialize(heapSize);

    for(int i = 0 ; i < heapSize ; i++)
    {
        std::cout << "Enter element " << std::endl;
        std::cin >> userInput;

        heap.Insert(userInput);
    }

    std::cout << std::endl;
    heap.Print();
    std::cout << std::endl;
    std::cout << std::endl;
    
    heap.HeapSort();

    return 0;
}