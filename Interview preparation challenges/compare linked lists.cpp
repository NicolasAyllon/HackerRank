// Solution
// Given two linked lists, return whether they have the same data
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    // If identical head pointers are passed in, the lists must be the same
    if(head1 == head2)                       return true;
    // If only one of the head pointers is null, return false
    if(head1 == nullptr && head2 != nullptr) return false;
    if(head1 != nullptr && head2 == nullptr) return false;
    
    // At this point, head pointers must be different and not null.
    // Create current pointers to traverse list
    SinglyLinkedListNode* current1 = head1;
    SinglyLinkedListNode* current2 = head2;
    // and check whether each data values are the same and stop when either is null
    while(current1 != nullptr && current2 != nullptr) {
        if(current1->data != current2->data) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    // At this point, we've reached the end of one or both lists
    // So either current1 = nullptr OR current2 = nullptr
    
    // If we're at the end of both lists
    //   return true if both currents point to null
    // If not, then one of the lists must have more nodes
    //   so the lists aren't the same.
    return (current1 == nullptr && current2 == nullptr);
}