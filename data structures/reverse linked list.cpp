// Solution:
// Reverse linked list and return pointer to new head
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    // list is empty, return head = nullptr
    if(head == nullptr) { return head; }
    // list has 1 node, no action required, return head
    if(head->next == nullptr) { return head; }
    // Program has reached this point, so the list has more than 1 node

    // Create pointers:
    // current points to 2nd item and previous pointing to 1st
    SinglyLinkedListNode* current = head->next;
    SinglyLinkedListNode* previous = head;
    head->next = nullptr; // previous points to former head of list
    
    // traverse list until current = nullptr (and previous points to last item)
    while(current != nullptr) {
        SinglyLinkedListNode* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode; // on the last item, current = nullptr
    }
    // now current = nullptr, so previous is the former tail, or new head
    head = previous;
    return head;  
}