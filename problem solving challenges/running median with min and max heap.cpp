#include <vector>
#include <algorithm>
using std::vector;

// Helping method declarations
bool compare(int a, int b);
void push_min_heap(int value, vector<int>& h);
int pop_min_heap(vector<int>& h);
void push_max_heap(int value, vector<int>& h);
int pop_max_heap(vector<int>& h);
float calculateMedian(vector<int>& lower, vector<int>& upper);

// Problem:
// Given a vector of ints, a, return a vector of running medians
// as values from the vector are added to a set.
//
// Solution:
// To find the running median as elements come in from a vector
// Use 2 heaps, a max heap for values below the median
// and a min heap for values above the median
vector<double> runningMedian(vector<int> a) {
    vector<double> medians;
    vector<int> lower_heap; // make max heap for values above median
    vector<int> upper_heap; // make min heap for values above median
    float median = 0;
    for(int val: a) {
        // if below median
        if(val <= median) {
            // If lower heap is already bigger (by 1)
            if(lower_heap.size() > upper_heap.size()) {
                // move value from lower to upper
                push_min_heap(pop_max_heap(lower_heap), upper_heap);
            }
            // push new value onto lower
            push_max_heap(val, lower_heap);
        }
        // If above median
        else if (val > median) {
            // If upper heap is already bigger (by 1)
            if(upper_heap.size() > lower_heap.size()) {
                // move value from upper to lower
                push_max_heap(pop_min_heap(upper_heap), lower_heap);
            }
            // push new value onto upper
            push_min_heap(val, upper_heap);
        }
        // calculate median
        median = calculateMedian(lower_heap, upper_heap);
        // add median to medians vector
        medians.push_back(median);
    }
    return medians;
}


// Helping Methods:
//
// Create custom compare to return a > b (instead of default a < b).
// This makes a min heap because the value x at the top, so 
// x > a is false for all other elements a
// (meaning x is the min)
bool compare(int a, int b) {
     return a > b;
}

// Push value onto min heap (use custom compare)
void push_min_heap(int value, vector<int>& h) {
    h.push_back(value);
    push_heap(h.begin(), h.end(), compare);
}
// Pop value from min heap and return its value
int pop_min_heap(vector<int>& h) {
    int value_at_top = h[0];
    pop_heap(h.begin(), h.end(), compare);
    h.pop_back();
    return value_at_top;
}

// Push value onto max heap
void push_max_heap(int value, vector<int>& h) {
    h.push_back(value);
    push_heap(h.begin(), h.end());
}
// Pop value from max heap and return its value
int pop_max_heap(vector<int>& h) {
    int value_at_top = h[0];
    pop_heap(h.begin(), h.end());
    h.pop_back();
    return value_at_top;
}

// Return median given the lower (max) heap and upper (min) heap
float calculateMedian(vector<int>& lower, vector<int>& upper) {
    // If heaps are the same size, return the average of the two middle values
    if(lower.size() == upper.size()) {
        return (lower[0] + upper[0])/2.0;
    }
    // If different sizes, the median is at the top of the bigger heap
    else {
        return (lower.size() > upper.size() ? lower[0] : upper[0]);
    }
}