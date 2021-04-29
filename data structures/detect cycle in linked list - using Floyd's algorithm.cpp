// Solution:
// Floyd's cycle detection algorithm
bool has_cycle(SinglyLinkedListNode* head) {
    // If the list is empty or has just 1 node, there are no cycles
    if(head == nullptr || head->next == nullptr) return false;
    // The list has more than 1 node.
    // Traverse list with fast and slow pointers
    SinglyLinkedListNode* slow = head; // advances 1 node per iteration
    SinglyLinkedListNode* fast = head; // advances 2 nodes per iteration
    while(slow != nullptr && fast != nullptr) {
        // Advance slow pointer by 1 node
        slow = slow->next;
    
        // Advance fast pointer by 2 nodes, unless it already points to the end...
        if(fast->next != nullptr) { fast = fast->next->next; }
        // ...in that case, advance just 1 node (so now fast = nullptr)
        else { fast = fast->next; }
        
        // If fast catches up to slow, there must be a cycle.
        if(fast == slow) return true;
    }
    // The fast pointer reached the end of the list and is now null
    // so the list has no cycles.
    return false;
}