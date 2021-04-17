#include <bits/stdc++.h>
using namespace std;

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    // Empty list: set head to point at new node
    if(head == nullptr) {
        head = new SinglyLinkedListNode(data);
        return head;
    }
    // Program has reached this point, so list is not empty
    // Create current pointer and traverse list until pointing to last node
	SinglyLinkedListNode* current = head;
    while(current->next != nullptr) {
        current = current->next;
    }
    // Now current points to the last node in the list
    // Point current->next to new node, which is now at the end of the list
    current->next = new SinglyLinkedListNode(data);
    return head;
}