// Solution:
// Return the height of a binary tree with given root node.
//
// Note:
// Height is the number of edges from the root to the furthest leaf.
// A leaf node or an isolated node has a height of 0.

int height(Node* root) {
    if(root == nullptr) { 
        return -1;
        // Return -1 for a null node
        // because the formula for a leaf 
        // (which has both null children)
        // becomes:
        //
        // height(leaf) = 1 + max(-1, -1)
        //              = 1 + -1
        //              = 0
    }
    else {
        // Because there is 1 edge between a node and its subtrees
        // the height is recursively defined the maximum height
        // of its left and right subtrees
        // plus (+) 1 for the edge connecting them to the root
        return 1 + max(height(root->left), height(root->right));
    }
}
    
/* Node is defined as:
class Node {
    int data;
    Node* left;
    Node* right;
};
*/