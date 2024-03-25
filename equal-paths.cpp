#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
bool checkEqualPaths(Node* node, int& depth, int currentDepth);


bool equalPaths(Node * root)
{
    // Add your code below
    int depth = 0; // Used to store the depth of the first leaf encountered
    return checkEqualPaths(root, depth, 0);

}

bool checkEqualPaths(Node* node, int& depth, int currentDepth) {
    // Base case: If node is nullptr, it means this path is not valid (parent was a leaf)
    if (!node) return true;

    // If it's a leaf node
    if (!node->left && !node->right) {
        // If this is the first leaf node we've encountered, record its depth
        if (depth == 0) {
            depth = currentDepth;
            return true;
        }
        // For all subsequent leaf nodes, check if the depth matches the first one's
        return depth == currentDepth;
    }

    // Recurse down the left and right subtrees, and ensure both subtrees return true
    // and have equal path lengths
    return checkEqualPaths(node->left, depth, currentDepth + 1) &&
           checkEqualPaths(node->right, depth, currentDepth + 1);
}

