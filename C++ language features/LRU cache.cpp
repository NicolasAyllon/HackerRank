#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

// From HackerRank
// Doubly linked list (not STL)
struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};
// From HackerRank
class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};


// Solution
// Extend Cache to LRUCache (least recently used) 
class LRUCache : public Cache {
    protected:
        // Helping method to move a node with key to front of the list
        void moveToFront(int key) {
            // If the key isn't in the map, do nothing
            if(mp.find(key) == mp.end()) return;
            // If the key is already at the front node at the head of the list, no action required.
            // If not, move it to the front
            if(head != mp[key]) {
                Node* node = mp[key];
                // cur->prev is not NULL because this is not the 1st Node in the list
                node->prev->next = node->next;
                // if this isn't the last node, update next's prev to point to current's prev
                if(node->next != NULL) {
                    node->next->prev = node->prev;
                }
                // This is the last node, so update tail to point to current's prev
                else {
                    tail = node->prev;
                }
                // Update node's and head's pointers
                node->prev = NULL;
                node->next = head;
                head->prev = node;
                head = node;
            }
        }
        
    public:
        // Constructor
        LRUCache(int capacity) {
            cp = capacity;
            head = NULL;
            tail = NULL;
        }
        
        // Sets the node with the key to have the corresponding value
        void set(int key, int val) {
            // If the node with key is in the cache, it moves to the front
            if(mp.find(key) != mp.end()) {
                mp[key]->value = val; // update value in map
                moveToFront(key); // move to front in list
            }
            // If not in the cache
            else {
                // If already at capacity, delete last item in cache at end of list
                if(mp.size() == cp) {
                    // erase from map
                    mp.erase(mp.find(tail->key));
                    // erase from list
                    tail = tail->prev;
                    delete tail->next;
                    tail->next = NULL;  
                }
                // Create new node (still works if head == NULL)
                Node* node = new Node(NULL, head, key, val);
                // Add to map
                mp[key] = node;
                // If first element in list, set head and tail to point to it
                if(head == NULL) {
                    head = node;
                    tail = node;
                }
                // Already 1 element in list, update head to point to node
                else {
                    head->prev = node;
                    head = node; 
                }
            }
        }
        
        // Return the value associated with the key if the node is in the cache
        // Return -1 not in the cache
        int get(int key) {
            // If node with key is in cache
            if(mp.find(key) != mp.end()) {
                moveToFront(key); // move it to front of list
                return mp[key]->value; // return its value
            }
            else {
                return -1;
            }
        }
};


// From HackerRank
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
