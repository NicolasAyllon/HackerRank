#include <algorithm>
#include <vector>

using std::vector;

// Problem:
// https://www.hackerrank.com/challenges/jesse-and-cookies/
//
// Given a vector of values {a, b, ...}
// where a and b are the least and second least
// determine the number of iterations of the operation
//
// {a, b, ...} --> {..., a + 2b}
//
// where: 
//    a and b are removed
//    a + 2b is added
//
// such that all elements in the vector {...}
// are greater than or equal to threshold value k

// Solution:
// Use a min heap to access the minimum values a and b
// Pop a and b off the heap and then push (a + 2b) onto the heap
//
// After each iteration, it's sufficient to check the top of the heap, or
// the min >= k
// to know all values are >= k

bool compare(int a, int b); 
// forward declare custom comparison for heap (explained later)

int cookies(int k, vector<int> A) {
    // heapify vector A
    // so that the first element A[0] is the min
    std::make_heap(A.begin(), A.end(), compare);
    
    // start iteration counter i at 0
    int i = 0;
    // Continue as long as there are 2 values to combine
    while(A.size() >= 2) {
        // If minimum value is greater than or equal to k
        if(A[0] >= k) return i;
        // pop and save least & 2nd least values
        int least = A[0];
        std::pop_heap(A.begin(), A.end(), compare);
        A.pop_back();
        // 2nd least value is now at index 0
        int second_least = A[0];
        std::pop_heap(A.begin(), A.end(), compare);
        A.pop_back();
        
        // push new mixed value onto the vector
        A.push_back(least + 2*second_least);
        std::push_heap(A.begin(), A.end(), compare);
        
        // incrment iteration counter i
        ++i;
        // check whether min value
        // has reached threshold k
    }
    // There is just one value left, so check whether
    // it's greater than or equal to k
    return (A[0] >= k ? i : -1);
}

// Heap is a max-heap by default, 
// where the top is the element x 
// for which x < a is false for all other elements a
// (meaning x is the maximum)
//
// To make a min-heap, make custom comparator function
// compare(a, b) that returns a > b.
//
// Now, the top element x is the one for which 
// x > a is false for all other elements a
// (meaning x is the minimum)
bool compare(int a, int b) {
    return a > b;
}