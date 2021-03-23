#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // Read in size n of array
    // Fill with following n values on the next line
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int elementToAdd;
        cin >> elementToAdd;
        arr.push_back(elementToAdd);
    }
    
    // Read in 1-based index of element to delete
    int indexToDelete;
    cin >> indexToDelete;
    
    // Read in 1-based indices of range to delete: [first, last)
    int firstIndexToDelete;
    int lastIndexToDelete;
    cin >> firstIndexToDelete >> lastIndexToDelete;

    // change from 1- to 0-based indices
    indexToDelete--;
    firstIndexToDelete--;
    lastIndexToDelete--;

    // erase one element at indexToDelete
    arr.erase(arr.begin() + indexToDelete);
    // then erase from [first, last)
    arr.erase(arr.begin() + firstIndexToDelete, arr.begin() + lastIndexToDelete);
    
    // print size of vector on one line
    cout << arr.size() << '\n';
    // print contents of vector separated by spaces
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
