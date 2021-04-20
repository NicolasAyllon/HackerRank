// Solution:
// Print the tree's data in postorder traversal.
void postOrder(Node *root) {
    // Base case: node is null, so return.
    if(root == nullptr) {
        return;
    }
    // Otherwise, recursively call postOrder 
    // on the left child, then the right child
    // before printing out the current node's data.
    else {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << ' ';
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