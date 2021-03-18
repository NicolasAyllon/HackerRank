#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Solution
int main() {
    // Read in number of arrays n and queries q
    int n;
    int q;
    cin >> n >> q;
    vector<vector<int>> arr;
    vector<int> results;
    
    // For each of n arrays, read in number of elements k
    // and fill with following k values
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> arr_i; // array at index i in arr
        for(int j = 0; j < k; j++) {
            int element;
            cin >> element;
            arr_i.push_back(element);
        }
        // add arr_i to arr
        arr.push_back(arr_i);
    }
    
    // Read q queries for array at index i, element at index j
    for (int q_i = 0; q_i < q; q_i++) {
        int i, j;
        cin >> i >> j;
        results.push_back(arr[i][j]);
    }
    
    // Print the results of q queries
    for(int i = 0; i < q; i++) {
        cout << results[i] << endl;
    }
    return 0;
}