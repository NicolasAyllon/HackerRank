#include <queue>

using namespace std;

// Solution:
// Print each node's data using level order traversal
void levelOrder(Node * root) {
    // Create queue and push on root node
    queue<Node*> q;
    q.push(root);
    
    // Create current to simplify code in while loop below
    Node* current = nullptr;
    // The queue starts with just the root node.
    while(!q.empty()) {
        // Store the node at the front in current and print its data
        current = q.front();
        cout << current->data << ' ';
        // Push each of its non-null child nodes onto the queue
        if(current->left != nullptr) q.push(current->left);
        if(current->right != nullptr) q.push(current->right);
        // Pop off the current node
        q.pop();
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