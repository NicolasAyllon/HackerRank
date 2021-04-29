// Solution:
bool has_cycle(SinglyLinkedListNode* head) {
    // Use set to store pointers to each node seen
    set<SinglyLinkedListNode*> visitedNodes;
    // Traverse list with current pointer
    SinglyLinkedListNode* current = head;
    while(current != nullptr) {
        // If the current node has been seen before,
        // This is a cycle so return true immediately
        if(visitedNodes.find(current) != visitedNodes.end()) {
            return true;
        }
        // Add node to set
        visitedNodes.insert(current);
        // Advance current
        current = current->next;
    }
    // At this point, the entire list has been processed
    // and never visited the same node more than once,
    // so the list has no cycles.
    return false;
}