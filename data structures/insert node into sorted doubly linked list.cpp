// Solution:
// Insert a new node into a doubly linked list, maintaining sort order
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    // Create new node with the data
    DoublyLinkedListNode* new_node = new DoublyLinkedListNode(data);
    
    // List is empty, so create new_node and return it as the head
    if(head == nullptr) {
        return new_node;
    }
    
    // List has 1 or more nodes
    // If new node's data is less than head's, insert at beginning
    if(data < head->data) {
        head->prev = new_node;
        new_node->next = head;
        return new_node;
    }
    // Otherwise, traverse until next node's data is >= new node's data
    else {
        DoublyLinkedListNode* current = head;    
        while(current->next != nullptr && current->next->data < data) {
            current = current->next;
        }
        // Now next node's data >= new node's data 
        // or current points to the last node.
        // Insert new node after current and before current->next
        if(current->next != nullptr) {
            current->next->prev = new_node;
        }
        new_node->next = current->next;
        new_node->prev = current;
        current->next = new_node;
    }
    return head;
}