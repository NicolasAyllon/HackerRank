#include <deque>
using namespace std;

// Solution:
// For an array of integers and a sliding window length
// Calculate the max of each sliding window and 
// return the min of all possible maxes.
vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int> result;
    // Each query is the size of the sliding window, k
    for(int k: queries) {
        int n = arr.size();
        deque<int> d;
        vector<int> sliding_window_maxes;
        
        // Step 1:
        // Find max of first k elements (indices 0 to k-1)
        // and push onto maxes vector
        for(int i = 0; i < k; ++i) {
            // remove indices from back corresponding to elements
            // less than or equal to element at current index
            while(!d.empty() && arr[d.back()] <= arr[i]) {
                d.pop_back();
            }
            // add index to back of deque
            d.push_back(i);
        }
        // push index onto maxes vector
        sliding_window_maxes.push_back(arr[d.front()]);
        
        // Step 2:
        // process remaining elements
        for(int i = k; i < n; ++i) {
            // remove indices from front of deque that are out of the window
            while(!d.empty() && d.front() <= i - k) {
                d.pop_front();
            }
            // remove indices from back corresponding to elements 
            // less than or equal to the element at the current index
            while(!d.empty() && arr[d.back()] <= arr[i]) {
                d.pop_back();
            }
            // add index to back of deque
            d.push_back(i);
            // The index at front of deque corresponds to the max element
            // in the window, so push it onto the maxes vector 
            // (max of elements indexed i - k + 1 to i)
            sliding_window_maxes.push_back(arr[d.front()]);
        }
        
        // Step 3:
        // calculate minimum of maxes vector
        // The result 
        int min_of_maxes = sliding_window_maxes.front();
        for(int max: sliding_window_maxes) {
            if(max < min_of_maxes) {
                min_of_maxes = max;
            }
        }
        result.push_back(min_of_maxes);
    }
    return result;
}
