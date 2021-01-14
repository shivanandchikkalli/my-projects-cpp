#include<iostream>

#include "chaining.h"

int main()
{
    Chaining chain;

    chain.Insert(100);
    chain.Insert(200);
    chain.Insert(300);
    chain.Insert(3);
    chain.Insert(103);
    chain.Insert(133);
    chain.Insert(433);
    chain.Insert(55);
    chain.Insert(75);
    chain.Insert(67);
    chain.Insert(417);
    chain.Insert(617);
    chain.Insert(99);

    chain.Print();

    std::cout << "Searching 117 : " << chain.Search(117) << std::endl;
    std::cout << "Searching 99 : " << chain.Search(99) << std::endl;
    std::cout << "Searching 75 : " << chain.Search(75) << std::endl;

    chain.Delete(99);
    chain.Delete(75);
    chain.Delete(917);
    chain.Delete(517);

    chain.Print();

    return 0;
}