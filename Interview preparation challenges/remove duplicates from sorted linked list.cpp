// Solution:
// Remove duplicates from linked list
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    //If the list is empty or has just 1 node, return it
    if(head == nullptr || head->next == nullptr) return head;
    // List has more than 1 node
    SinglyLinkedListNode* current = head; // current traverses list starting at head
    SinglyLinkedListNode* nodeToDelete = nullptr; // temporarily store nodes to delete
    //
    while(current->next != nullptr) {
        // If next node's data matches this one's
        if(current->data == current->next->data) {
            // mark it for deletion
            nodeToDelete = current->next;
            // set current's next to point to the one after the next node
            current->next = current->next->next;
            delete nodeToDelete;
        }
        // Next node's data is different, so advance current
        else {
            current = current->next;
        }
    }
    return head;
}