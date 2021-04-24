// Solution:
// Given 2 integer values in a binary search tree
// return a pointer to their lowest common ancestor (lca)

// Method 1:
// Use three pointers: next_1 seeking v1, next_2 seeking v2, and current
// When next_1 and next_2 are the same, advance current
// When they differ, return current
Node* lca(Node* root, int v1,int v2) {
    // Write your code here.
    Node* current = root;
    Node* next_1 = root;
    Node* next_2 = root;
    
    while(true) {
        if(v1 < current->data) { next_1 = current->left; }
        if(v1 > current->data) { next_1 = current->right; }
        // implied:
        // if(v1 == current->data) { next_1 = current; }

        if(v2 < current->data) { next_2 = current->left; }
        if(v2 > current->data) { next_2 = current->right; }
        // implied:
        // if(v2 == current->data) { next_2 = current; }
        
        // If v1 or v2 isn't in the tree, return null
        if(next_1 == nullptr || next_2 == nullptr) return nullptr;
        
        // If both nexts are the same, and not equal to the current node
        // advance current to next, otherwise break
        if(next_1 == next_2 && next_1 != current) { current = next_1; }
        else { return current; }
    }
}

// Method 2:
// Recursively call lca() on left or right child nodes
// until it is not true that v1 and v2 both lie in the same subtree
Node* lca(Node* root, int v1, int v2) {
    // Both values are less than root, so lca lies to the left
    if(v1 < root->data && v2 < root->data) {
        return lca(root->left, v1, v2);
    }
    // Both values are greater than root, so lca lies to the right
    if(v1 > root->data && v2 > root->data) {
        return lca(root->right, v1, v2);
    }
    // Otherwise, root (the Node* parameter) is the lca,
    // so return it
    return root;
}

/* Nodes in the tree are defined as:

class Node {
    int data;
    Node* left;
    Node* right;
};

*/
