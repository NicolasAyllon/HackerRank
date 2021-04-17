// Solution:
// Given head pointers to 2 sorted lists, merge the lists
// and return a pointer to the head of the merged list
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    // If either head pointer is null, return the other one
    if(head1 == nullptr) return head2;
    if(head2 == nullptr) return head1;
    // At this point, both head pointers are not null
    SinglyLinkedListNode* merged_head = nullptr;
    SinglyLinkedListNode* merged_current = nullptr;
    SinglyLinkedListNode* current1 = head1;
    SinglyLinkedListNode* current2 = head2;
    
    // Step 1:
    // Add first node to merged list using whichever data is smaller.
    // This node will be the head of the merged linked list to return.
    if(current1->data <= current2->data) {
        merged_head = new SinglyLinkedListNode(current1->data);
        current1 = current1->next;
        merged_current = merged_head;
    }
    else {
        merged_head = new SinglyLinkedListNode(current2->data);
        current2 = current2->next;
        merged_current = merged_head;
    }
    
    // Step 2:
    // Build the rest of the merged list.
    // while current1 and current2 are not both null
    // (stop when both are null)
    while(current1 != nullptr || current2 != nullptr) {
        // Since current1 and current2 are not both null
        // if one is null, the other is not
        // so add its data to the merged list
        if(current1 == nullptr) {
            merged_current->next = new SinglyLinkedListNode(current2->data);
            current2 = current2->next;
        }
        else if(current2 == nullptr) {
            merged_current->next = new SinglyLinkedListNode(current1->data);
            current1 = current1->next;
        }
        // Both current1 and current2 are not null 
        // so we can compare their data
        // add the smaller data to the merged list
        // and advance the corresponding current pointer
        else if(current1->data <= current2->data) {
            merged_current->next = new SinglyLinkedListNode(current1->data);
            current1 = current1->next;
        }
        else {
            merged_current->next = new SinglyLinkedListNode(current2->data);
            current2 = current2->next;
        }
        // Finally, advance the merged_current pointer
        merged_current = merged_current->next;
    }
    // Now both current1 and current2 are null
    // so both lists have been processed.
    // Return pointer to head of merged list
    return merged_head;
}