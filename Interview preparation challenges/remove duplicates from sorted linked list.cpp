// Solution:
// Remove duplicates from linked list
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    //If the list is empty return it
    if(head == nullptr) return head;
    // List is not empty
    SinglyLinkedListNode* unique_head = head; // point to head of unique list, returned
    SinglyLinkedListNode* unique_tail = head; // points to tail of unique list
    SinglyLinkedListNode* current = head; // current traverses list starting at head
    SinglyLinkedListNode* temp = nullptr; // will point to nodes to be deleted
    // advance current to next node
    current = current->next;
    while(current != nullptr) {
        // If current node matches the tail of the unique list, delete it and advance
        if(current->data == unique_tail->data) {
            temp = current;
            current = current->next;
            delete temp;
        }
        // Current differs from unique_tail, so append to unique_tail
        // and advance both current and unique_tail;
        else {
            unique_tail->next = current;
            unique_tail = current;
            current = current->next;
        }
    }
    // After reaching end of list, set tail's next to null
    unique_tail->next = nullptr;
    return unique_head;
}