#include <iostream>
#include <algorithm>
using namespace std;

// Solution:
// Implement queue using main stack and buffer stack.
class sQueue {
    private:
        stack<int> mainQueue;
        stack<int> buffer;
        // If buffer is more than size of mainQueue
        // move all of buffer into mainQueue to refill it
        void refill() {
            if(buffer.size() > mainQueue.size()) {
                stack<int> updatedQueue;
                while(!buffer.empty()) {
                    updatedQueue.push(buffer.top());
                    buffer.pop();
                }
                // invert main into (now empty) buffer
                while(!mainQueue.empty()) {
                    buffer.push(mainQueue.top());
                    mainQueue.pop();
                }
                // invert buffer onto updatedQueue
                while(!buffer.empty()) {
                    updatedQueue.push(buffer.top());
                    buffer.pop();
                }
                mainQueue = updatedQueue;
            }
        }
    public:
        sQueue() {}
        void enqueue(int x) {
            buffer.push(x);
            refill();
        }
        int dequeue() {
            int item = mainQueue.top();
            mainQueue.pop();
            refill();
            return item;
        }
        int front() {
            return mainQueue.top();
        }
};

// Process queries to 
// (1) add elements to queue 
// (2) remove elements from queue, or 
// (3) print the element at the front
int main() {
    int q;
    cin >> q;
    sQueue sQ;
    while(q--) {
        int queryType;
        cin >> queryType;
        switch(queryType) {
            // Enqueue
            case 1: {
                int x;
                cin >> x;
                sQ.enqueue(x);
                break;
            }
            // Deque
            case 2: {
                sQ.dequeue();
                break;
            }
            // Print front element
            case 3: {
                cout << sQ.front() << '\n';
                break;
            }
        }
    }
    return 0;
}