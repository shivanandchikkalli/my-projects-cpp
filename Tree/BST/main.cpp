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

    tree.RInsert(tree.getRoot(), userInput);

    while(!exitTreeCreation)
    {
        std::cout << "Enter element " << std::endl;
        std::cin >> userInput;

        if(userInput != -1) 
            tree.RInsert(tree.getRoot(), userInput);
        else
            break;
    }

    tree.printTree(tree.getRoot());

    std::cout << std::endl << "Count() => " << tree.count(tree.getRoot()) << std::endl;

    std::cout << std::endl << "Height() => " << tree.height(tree.getRoot()) << std::endl;

    std::cout << "Enter element to search" << std::endl;
    std::cin >> userInput;

    std::cout << "Iterative Search Result : " << tree.Search(userInput) << std::endl;
    std::cout << "Recursive Search Result : " << tree.RSearch(tree.getRoot(), userInput) << std::endl;

    std::cout << "In-Order Predecessor : " << tree.Get_inorder_predecessor(tree.getRoot()) << std::endl;
    std::cout << "In-Order successor : " << tree.Get_inorder_successor(tree.getRoot()) << std::endl;

    tree.printTree(tree.getRoot());

    std::cout << "Enter element to Delete" << std::endl;
    std::cin >> userInput;

    tree.Delete(userInput);

    tree.printTree(tree.getRoot());

    return 0;
}