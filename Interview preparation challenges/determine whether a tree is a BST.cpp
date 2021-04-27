// Solution:
// An inorder traversal of a BST visits the nodes in ascending order.
// If the current node's data is less than or equal to the previous one's
// then the tree cannot be a BST.
bool checkBST(Node* root) {
    // prev stores the previously visited node's data
    int prev = -1; // It is given that 0 <= data <= 10,000
    bool result = true; // Store the answer during inorder traversal
    // Inorder traversal
    checkBST(root, prev, result);
    // For a BST, result still = true
    return result;
}

void checkBST(Node* root, int& prev, bool& result) {
    // Base case: an empty tree is a BST (vacuous truth)
    if(root == nullptr) return;
    
    // else (implied)
    // Inorder Traversal
    // 1. visit left subtree
    checkBST(root->left, prev, result);
    // 2. visit current node
    // check whether this node's data is <= to previous (out of order data)
    // or whether result has already been set to false in the above call
    if(root->data <= prev || !result) {
        // If so, the tree is not a BST
        result = false; 
        return;
    }
    // update previous node's value to this one
    prev = root->data;
    // 3. visit right subtree
    checkBST(root->right, prev, result);
}

/*
Node struct is defined as:
    struct Node {
        int data;
        Node* left;
        Node* right;
    }
*/