// tree.h
// Class: cs260
// Author: Juan Gonzalez
// Purpose:

#pragma once
#include "website.h"

class Tree
{

public:

    Tree();
    void add(const Website& a_website);


private:

    struct Node
    {
        Node(const Website& a_website)
        {
            data = new Website(a_website);
            left = right = nullptr;
        }

        Website* data;                      
        Node* left;
        Node* right;
    };

    Node* m_root;
    int m_size;

    void _addNode(Node*& curr_root, const Website& a_website);

};