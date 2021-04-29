#include<queue>
#include<deque>

void topView(Node * root) {
    // Return immediately if root is null
    if(root == nullptr) return;
    
    // Otherwise, tree has at least 1 node
    // Create queue of pairs for level order traversal
    // Each pair stores the node and its position, where
    queue<pair<Node*, int>> q;
    pair<Node*, int> p(root, 0);
    q.push(p);
    // Position of root is 0
    // Position decreases by 1 following an edge to left child
    // Position increases by 1 following an edge to right child
    
    // Store min and max positions seen so far
    int min = 0;
    int max = 0;
    
    // Create deque to organize nodes 
    // that will appear in the top view
    deque<Node*> d;
    d.push_front(root);
    
    while(!q.empty()) {
        // Store Node* and position from pair at front of queue
        // Then, pop
        Node* current_node = q.front().first;
        int pos = q.front().second;
        q.pop();
        
        // If node's position is furthest left seen so far
        // push to front of deque and update min
        if(pos < min) {
            d.push_front(current_node);
            min = pos;
        }
        // If node's position if furthest right seen so far
        // push to back of deque and update max
        else if(pos > max) {
            d.push_back(current_node);
            max = pos;
        }
        
        // For level order traversal,
        // Push pairs containing left and right non-null children
        // and their corresponding positons onto the queue
        if(current_node->left != nullptr) {
            pair<Node*, int> p_left(current_node->left, pos-1);
            q.push(p_left);
        }
        if(current_node->right != nullptr) {
            pair<Node*, int> p_right(current_node->right, pos+1);
            q.push(p_right); 
        }
    }
    // Print data for all top view nodes
    // organized in the deque
    while(!d.empty()) {
        cout << d.front()->data << ' ';
        d.pop_front();
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