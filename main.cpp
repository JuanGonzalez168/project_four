// hello.cpp
// Class: cs260
// Author: Juan Gonzalez
// Purpose: 

#include <iostream>
#include "tree.h"
#include "website.h"

int main()
{

    Website website1("topic", "a", "","","",5);
    Website website2("topic", "c", "", "", "",5);
    Website website3("topic", "d", "", "", "",5);
    Website website4("topic", "e", "", "", "",5);
    Website website5("topic", "f", "", "", "",5);


    Tree binaryTree;

    binaryTree.add(website1);
    binaryTree.add(website2);
    binaryTree.add(website3);
    binaryTree.add(website4);
    binaryTree.add(website5);

    binaryTree.display();

    std::cout << "Height: " << binaryTree.getHeight() << "\n";

    std::cout << "End of the program!" << std::endl;
    return 0;
}
