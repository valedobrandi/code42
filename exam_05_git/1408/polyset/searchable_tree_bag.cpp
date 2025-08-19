#include "searchable_tree_bag.hpp"

// Default constructor: calls tree_bag's default constructor
searchable_tree_bag::searchable_tree_bag() :tree_bag() {};
// Copy constructor: uses tree_bag's copy constructor to duplicate the tree
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other) :tree_bag(other) {};

searchable_tree_bag::~searchable_tree_bag() {};

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other) {
    if (this != &other) {
        tree_bag::operator=(other); // Let tree_bag handle deep copying
    }

    return *this;
}

// has(): search for a value in the binary search tree
bool searchable_tree_bag::has(int i) const {
     // Start search from the root node
    Node* current = root;
    // Traverse until we reach a null pointe
    while (current) {
        // Found the value → return true
        if (current->value == i) return true;
        if (current->value > i) current = current->left;  // If target is smaller, go left
        else current = current->right; // If target is bigger, go right
    }
    return false;
}