// tree.cpp
// Class: cs260
// Author: Juan Gonzalez
// Purpose:


#include "tree.h"


Tree::Tree() : m_root(nullptr), m_size(0)
{}


Tree::~Tree()
{
   _destroy(m_root); 
}


void Tree::_destroy(Node*& curr_root)
{
    if(curr_root)
    {
        _destroy(curr_root->left);
        _destroy(curr_root->right);

        delete curr_root->data;
        delete curr_root;
        curr_root = nullptr;
    }
}


bool Tree::isEmpty() const
{
    return (m_size < 0) ? true : false;
}

int Tree::getHeight() const
{
     return _maxHeight(m_root);
}

int Tree::_maxHeight(Node* curr_root) const
{
    if(!curr_root)
    {
        return 0;        
    }
    else
    {
       int left_height = _maxHeight(curr_root->left);
       int right_height = _maxHeight(curr_root->right);
       return (left_height > right_height) ? left_height + 1 : right_height + 1;
    }
}

void Tree::add(const Website& a_website)
{
    _addNode(m_root, a_website);
    m_size++;
}


void Tree::_addNode(Node*& curr_root, const Website& a_website)
{
    if(!curr_root)
    {
        curr_root = new Node(a_website);
    }

    else if(a_website < *(curr_root->data))
    {
        _addNode(curr_root->left, a_website);
    }
    
    else
    {
        _addNode(curr_root->right, a_website);
    }
}


void Tree::display() const 
{
    //_displayInOrder(m_root);
    //_displayPreOrder(m_root);
    _displayPostOrder(m_root);
}


void Tree::_displayInOrder(Node* curr_root) const
{
    if(curr_root)
    {
        _displayInOrder(curr_root->left);
        std::cout << *(curr_root->data->getKeyword()) << "\n";
        _displayInOrder(curr_root->right);
    }
    
}


void Tree::_displayPreOrder(Node* curr_root) const
{
    if(curr_root)
    {
        std::cout << *(curr_root->data->getKeyword()) << "\n";
        _displayPreOrder(curr_root->left);
        _displayPreOrder(curr_root->right);
    }
}


void Tree::_displayPostOrder(Node* curr_root) const
{
    _displayPreOrder(curr_root->left);
    _displayPreOrder(curr_root->right);
    std::cout << *(curr_root->data->getKeyword()) << "\n";
}


void Tree::loadFromFile(const char* FILE)
{
    std::cout << "Loaded from file!";

}