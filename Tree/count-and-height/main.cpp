#include<iostream>
#include<queue>

#include "tree.h"

int main()
{
    std::queue<Node*> queue;

    Tree tree;

    bool exitTreeCreation = false;

    int userInput = 0;

    std::cout << "Enter root element" << std::endl;
    std::cin >> userInput;

    queue.push(tree.addRoot(userInput));

    Node* temp = NULL;


    while(!exitTreeCreation)
    {
        std::cout << "press -1 to stop adding tree elements..." << std::endl;
        std::cin >> userInput;
        if(userInput == -1)
            break;
        temp = queue.front();
        queue.pop();

        std::cout << "Enter left element of " << temp->element << std::endl;
        std::cin >> userInput;

        if(userInput != -1) queue.push(tree.addLeft(temp, userInput));

        std::cout << "Enter right element " << temp->element << std::endl;
        std::cin >> userInput;

        if(userInput != -1) queue.push(tree.addRight(temp, userInput));

    }

    tree.printTree(tree.getRoot());

    std::cout << std::endl << "Count() => " << tree.count(tree.getRoot()) << std::endl;
    
    return 0;
}