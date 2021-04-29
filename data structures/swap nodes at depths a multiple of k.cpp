#include <vector>

// Declarations:
// Pairs of recursive methods and helper called
void storeInOrderTraversal(vector<vector<int>>& tree, vector<vector<int>>& results);
void storeInOrderTraversal(vector<vector<int>>& tree, vector<int>& traversal, int currentIndex);

void swapNodesAtMultiplesOfDepth(vector<vector<int>>& tree, int k);
void swapNodesAtMultiplesOfDepth(vector<vector<int>>& tree, int k, int currentIndex, int currentDepth);



// Overall Function
// ****************
// The tree, indexes, is a vector<vector<int>> where indexes[i] (a vector<int>) 
// contains the 1-based index of left child, indexes[i][0] 
// and the 1-based index of right child, indexes[i][1]
// Note: nodes of the tree, indexes, hold no data
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> results;
    for(int k: queries) {
        // Swap left and right child of nodes 
        // at depths a multiple of k (k, 2k, 3k, ...)
        swapNodesAtMultiplesOfDepth(indexes, k);
        // Stores an inorder traversal vector in results at each step
        storeInOrderTraversal(indexes, results);
    }
    return results;
}


// Supporting Functions
// ********************
void swapNodesAtMultiplesOfDepth(vector<vector<int>>& tree, int k) {
    int rootIndex = 1;
    int rootDepth = 1;
    // Use helper method to traverse tree using postorder 
    // and swap children at k-multiple depths
    // Note: Helper method takes in 1-based index and handles conversion to 0-based
    swapNodesAtMultiplesOfDepth(tree, k, rootIndex, rootDepth);
}
// Helping Method with 2 more parameters: currentIndex and currentDepth
// Use Postorder Traversal to recursively visit both subtrees before root
void swapNodesAtMultiplesOfDepth(vector<vector<int>>& tree, int k, int currentIndex, int currentDepth) {
    // Base case: -1 represents the index of a null node, so return
    if(currentIndex == -1) { return; }
    
    // else (implied)
    int leftChildIndex = tree[currentIndex-1][0];
    int rightChildIndex = tree[currentIndex-1][1];
    
    // Postorder traverse to swap in both subtrees 
    // before swapping current node's left and right child
    //
    // visit left child
    swapNodesAtMultiplesOfDepth(tree, k, leftChildIndex, currentDepth+1);
    // visit right child
    swapNodesAtMultiplesOfDepth(tree, k, rightChildIndex, currentDepth+1);
    // The current depth is a multiple of k, so swap nodes
    // Child indices are stored already, so no need for temp
    if(currentDepth % k == 0) {
        tree[currentIndex-1][0] = rightChildIndex; // set left child to right
        tree[currentIndex-1][1] = leftChildIndex; // set right child to left
    }
}


void storeInOrderTraversal(vector<vector<int>>& tree, vector<vector<int>>& results) {
    vector<int> traversal;
    int rootIndex = 1;
    // Use helper method to traverse tree in order 
    // and store indices in traversal vector
    // Note: Helper method takes in 1-based index and handles conversion to 0-based
    storeInOrderTraversal(tree, traversal, rootIndex);
    results.push_back(traversal);
}
// Helping Method processes a 1-based currentIndex
void storeInOrderTraversal(vector<vector<int>>& tree, vector<int>& traversal, int currentIndex) {
    // Base case: -1 represents the index of a null node, so return
    if(currentIndex == -1) return;
    
    // else (implied)
    // get 1-based indices of left and right child
    // subtract 1 from currentIndex to convert 1-based to 0-based
    int leftChildIndex = tree[currentIndex-1][0];
    int rightChildIndex = tree[currentIndex-1][1];
    
    // visit left subtree
    storeInOrderTraversal(tree, traversal, leftChildIndex);
    // push 1-based current index onto traversal vector
    traversal.push_back(currentIndex);
    // visit right subtree
    storeInOrderTraversal(tree, traversal, rightChildIndex);
}