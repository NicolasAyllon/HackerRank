int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    // Start current1 at head1 and current2 at head2 and traverse lists.
    SinglyLinkedListNode* current1 = head1;
    SinglyLinkedListNode* current2 = head2;
    
    while(current1 != current2) { 
        // Current 1
        // Traverse list 1.
        // When current1 reaches the end of list1, reset to head2
        // Then traverse list 2.
        if(current1->next == nullptr) {
                current1 = head2;
        }
        else { 
            current1 = current1->next; 
        }
        
        // Current 2
        // Traverse list 2.
        // When current1 reaches the end of list1, reset to head1
        // Then traverse list 1.
        if(current2->next == nullptr) {
            current2 = head1;
        }
        else { 
            current2 = current2->next; 
        }
    }
    // After finishing the list and starting at the beginning of the other
    // current1 and current2 have converged on the merged node
    // current1 == current2
    // so return the data
    return current1->data;
}