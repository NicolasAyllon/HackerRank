// Solution:
// Reverse a doubly linked list and return the new head of the list.
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    
    // List has 0 or 1 nodes, so return head
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    
    // List has 2 or more nodes, so create current and temp pointers.
    DoublyLinkedListNode* current = head;
    DoublyLinkedListNode* temp = nullptr;
    
    // Traverse list with current, using temp to swap next and prev.
    while(current != nullptr) {
        // swap prev and next
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        // If prev is null, current points to the new head of the list (former tail).
        if(current->prev == nullptr) { head = current; }
        // Now that prev points to the next node, follow it.
        current = current->prev;
    }
    return head;
}