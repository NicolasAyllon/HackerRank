// Solution:
// Inserts a node into a self-balancing AVL tree and 
// performs necessary rotations to ensure the tree is balanced,
// (For all nodes, heights of left and right subtrees differ by at most 1.)
int heightOf(node* root) {
    if(root == nullptr) { return -1; }
    else return root->ht;
}

// Note:
// It is okay to pass root (a pointer to node) by value here
// because the function doesn't change it. 
// The function changes fields (ht) in the object it points to (*root).
// Recall root->ht is equivalent to (*root).ht
//
void updateHeight(node* root) {
    root->ht = 1 + max(heightOf(root->left), heightOf(root->right));
}

// Returns the balance factor for node, defined as:
// (height of left subtree) - (height of right subtree)
int balanceFactor(node* root) {
    return heightOf(root->left) - heightOf(root->right); 
}

// Note: For the following functions:
//   rightRotate(...)
//   leftRotate(...)
//   balance(...)
// The parameter root (a pointer to node) needs to change
// to point to the new root after the rotation, or balance
// For changes to survive past the function, pass by reference (node*&)

// Rotates subtree at root so that its new root is root->left
// Afterwards, root points to the new root (previously root->left)
void rightRotate(node*& root) {
    // change left child's right subtree to root's left subtree
    node* new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;
    // update heights
    updateHeight(root);
    updateHeight(new_root);
    root = new_root;
}

// Rotates subtree at root so that its new root is root->right
// Afterwards, root points to the new root (previously root->right)
void leftRotate(node*& root) {
    // change right child's left subtree to root's right subtree
    node* new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    // update heights
    updateHeight(root);
    updateHeight(new_root);
    root = new_root;
}

// Balances subtree at root and updates heights
// Afterwards, root points to the new root of the balanced tree
void balance(node*& root) {
    // Update height
    updateHeight(root);
    // left heavy
    if(balanceFactor(root) == 2) {
        // If left-right case, reduce to left-left case
        if(balanceFactor(root->left) == -1) { leftRotate(root->left); }
        // left-left case
        rightRotate(root);
    }
    // right heavy
    else if(balanceFactor(root) == -2) {
        // If right-left case, reduce to right-right case
        if(balanceFactor(root->right) == 1) { rightRotate(root->right); }
        // right-right case
        leftRotate(root);
    }
}

// Recursively traverse tree to find where to insert val
node* insert(node* root, int val)
{
	// Base case: root is null, return new node
    if(root == nullptr) {
        node* nodeToInsert = new node;
        nodeToInsert->val = val;
        nodeToInsert->left = nullptr;
        nodeToInsert->right = nullptr;
        nodeToInsert->ht = 0;
        return nodeToInsert;
    }
    // else (implied)
    //
    // Note:
    // Updates or changes to root propagate back up to the root of the tree
    // so parent node's left and right pointers are updated
    if(val < root->val) {
        root->left = insert(root->left, val);
    }
    if(val > root->val) {
        root->right = insert(root->right, val);
    }
    // if(val == root->val) { // do nothing } (implied)
    
    // Balance subtree at root (possibly changing root)
    // before ascending back to root of entire tree
    balance(root);
    return root;
}

/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */