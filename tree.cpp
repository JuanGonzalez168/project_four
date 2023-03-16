// tree.cpp
// Class: cs260
// Author: Juan Gonzalez
// Purpose:


#include "tree.h"


Tree::Tree() : m_root(nullptr), m_size(0)
{}

void Tree::add(const Website& a_website)
{
    _addNode(m_root, a_website);
}

void Tree::_addNode(Node*& curr_root, const Website& a_website)
{
    if(!curr_root)
    {
        curr_root = new Node(a_website);
        m_size++;
        return;
    }

    if(*(curr_root->data) < a_website)
    {

    }
}