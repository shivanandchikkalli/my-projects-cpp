#include<iostream>
#include<queue>

#include "tree.h"

int main()
{
    Tree tree;

    bool exitTreeCreation = false;

    int userInput = 0;

    std::cout << "Enter root element" << std::endl;
    std::cin >> userInput;

    tree.Pre_Order_Insert(userInput);

    while(!exitTreeCreation)
    {
        std::cout << "Enter element " << std::endl;
        std::cin >> userInput;

        if(userInput != -1) 
            tree.Pre_Order_Insert(userInput);
        else
            break;
    }

    tree.printTree(tree.getRoot());

    return 0;
}