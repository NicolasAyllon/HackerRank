// Solution:
// Insert a node with int data into a binary tree

// Method 1:
// Use recursion
Node* insert (Node* root, int data) {
    if(root == nullptr) {
        return new Node(data);
    }
    if(data < root->data) {
        root->left = insert(root->left, data);
    }
    if(data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Solution Method 2:
// Use while loop
Node* insert (Node* root, int data) {
    // If root is null, return pointer to new node
    if(root == nullptr) {
        return new Node(data);
    }
    
    // Store root to return after new node is inserted
    Node* current = root;
    
    // Traverse tree
    // Compare new node's data with current's 
    // to choose left or right
    while(true) {
        if(data < current->data) {
            // Left is null, so point to new node
            if (current->left == nullptr) { 
                current->left = new Node(data);
                break;
            }
            // Otherwise traverse left
            current = current->left;
        }
        else if(data > current->data) {
            // Right is null, so point to new node
            if(current->right == nullptr) {
                current->right = new Node(data);
                break;
            }
            // Otherwise traverse right
            current = current->right;
        }
        // There's already a node in the tree with that value, so do nothing
        // (data == current->data)
        else { break; }
    }
    return root;
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
