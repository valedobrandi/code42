#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag() {}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other) : tree_bag(other) {}
searchable_tree_bag::~searchable_tree_bag() {}
searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other) 
{
    if (this != &other)
    {
        tree_bag::operator=(other);
    }
    return *this;
}

bool searchable_tree_bag::has(int i) const {
    Node* current = root;
    while (current)
    {
        if (current->value == i) return true;
        if (current->value > i) current = current->left;
        else current = current->right;
    }
    return false;
}