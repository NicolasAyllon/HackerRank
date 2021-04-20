// Solution:
// Print the tree's data following inorder traversal
//
// Note: 
// If the tree is a binary search tree
// the data will print in sorted order.

void inOrder(Node *root) {
    // Base case: node is null, so return.
    if(root == nullptr) {
        return;
    }
    // Otherwise, recursively call inOrder 
    // on the left child
    // print the current node's data,
    // and then call inOrder on the right child.
    else {
        inOrder(root->left);
        cout << root->data << ' ';
        inOrder(root->right);
    }
}
    
/* Node is defined as:
class Node {
     public:
         int data;
         Node *left;
         Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/