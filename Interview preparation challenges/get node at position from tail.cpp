// Solution:
// Return the data at a node at a certain position
// from the tail of the list.
//
// For example:
// 4 -> 3 -> 2 -> 1 -> 0 -> null
// each number shows the node's position from the tail.
//
// Approach: 
// Traverse the list with two pointers. 
// The second lags behind the first so that 
// when the first reaches the end of the list
// the second points to the desired node.

int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    // make current and offset pointers
    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* current_offset = head;
    int index = 0;
    // Traverse list with current pointer
    // incrementing index each time.
    while(current->next != nullptr) {
        current = current->next;
        // When current is positionFromTail nodes from the head
        // the current_offset can begin moving from the head
        // maintaining the same distance from current.
        if(index >= positionFromTail) {
            current_offset = current_offset->next;
        }
        ++index;
    }
    // Then, when current points to the last item
    // current_offset points to the desired node
    // because it lags positionFromTail nodes behind current
    return current_offset->data;
}