 // Solution: 
 // Recursively call reversePrint() on the next node 
 // before printing the current node's data, 
 // so the list prints in reverse order.
void reversePrint(SinglyLinkedListNode* head) {
    // base case: !head = NULL = nullptr
    // print nothing, just return
    // (we've reached the end of the list)
    if(!head) {
        return;
    }
    // Otherwise call the function the next node in the list and print it first
    // THEN print this node's data
    else {
        reversePrint(head->next);
        cout << head->data << '\n';
    }
}