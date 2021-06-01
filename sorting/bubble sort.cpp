#include <vector>

// Bubble Sort
// Swap consecutive elements if left is greater than right.
// After 1 iteration, greatest element bubbles to the end of the array.
// Subsequent iterations stop at smaller indices as they put in the 2nd:
//   2nd iteration, the 2nd greatest element bubbles into place
//   3rd iteration, the 3rd greatest element bubbles into place
//   ...
void countSwaps(vector<int> a) {
    int swaps = 0;
    for(int i = 0; i < a.size(); ++i) {
        for(int j = 0; j < a.size()-1-i; ++j) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                ++swaps;
            }
        }
    }
    // Report number of swaps, first and last element
    cout << "Array is sorted in " << swaps << " swaps." << '\n';
    cout << "First Element: " << a[0] << '\n';
    cout << "Last Element: " << a[a.size()-1] << '\n';
}