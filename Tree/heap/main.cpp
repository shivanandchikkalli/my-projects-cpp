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

    int array[7] = {45,54,75,13,72,38,43};

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

    std::cout << std::endl;
    std::cout << std::endl;

    heap.Heapify2(array, 7);

    for(int i = 0 ; i < 7 ; i++)
    {
        std::cout << array[i] << " ";
    }

    return 0;
}