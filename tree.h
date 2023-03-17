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
    ~Tree();

    bool isEmpty() const;
    void add(const Website& a_website);
    int getHeight() const;
    void display() const;
    
    void loadFromFile(const char* FILE);


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
    void _destroy(Node*& curr_root);


    void _displayInOrder(Node* curr_root) const;
    void _displayPreOrder(Node* curr_root) const;
    void _displayPostOrder(Node* curr_root) const;
    int _maxHeight(Node* curr_root) const;
};

