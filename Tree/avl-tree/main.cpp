#include<iostream>
#include<queue>

#include "tree.h"

int main()
{
    Tree tree;

    Node* noderr = NULL;

    bool exitTreeCreation = false;

    int userInput = 0;

    std::cout << "Enter root element" << std::endl;
    std::cin >> userInput;

    tree.RInsert(tree.getRoot(), userInput);

    while(!exitTreeCreation)
    {
        std::cout << "Root is : " << tree.getRoot()->element << std::endl;
        std::cout << "Enter element " << std::endl;
        std::cin >> userInput;

        if(userInput != -1) 
            tree.RInsert(tree.getRoot(), userInput);
        else
            break;
    }

    tree.printTree(tree.getRoot());

    std::cout << std::endl << tree.getRoot()->element << std::endl;

    std::cout << std::endl << "Count() => " << tree.count(tree.getRoot()) << std::endl;

    std::cout << std::endl << "Height() => " << tree.height(tree.getRoot()) << std::endl;

    return 0;
}