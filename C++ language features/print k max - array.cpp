#include <iostream>
#include <deque> 
using namespace std;

// Solution
void printKMax(int arr[], int n, int k){
    int indexOfCurrentMax = -1;
    int currentMax = 0;
    
    // For first k indices
    // find current maximum
    for(int i = 0; i < k; i++) {
        // using >= updates indexOfCurrentMax if a newer (further right) value
        // is discovered that also equals currentMax
        if(arr[i] >= currentMax) { 
            currentMax = arr[i];
            indexOfCurrentMax = i;
        }
    }
    // print max of first subarray
    cout << currentMax;
    // for indices k and on
    for(int i = k; i < n; i++) {
        bool currentMaxStillInSubarray = (indexOfCurrentMax > i - k);
        
        // The new value arr[i] is bigger than currentMax,
        // so update currentMax (whether or not it's still in range).
        if(arr[i] >= currentMax) {
            currentMax = arr[i];
            indexOfCurrentMax = i;
        }
        // New value is less than currentMax, but if currentMax is still in the subarray
        // currentMax keeps its current value (no change).
        else if(!currentMaxStillInSubarray) {
            // recalculate max
            currentMax = arr[i - k + 1];
            indexOfCurrentMax = i - k + 1;
            for(int j = i - k + 1; j <= i; j++) {
                if(arr[j] >= currentMax) {
                    currentMax = arr[j];
                    indexOfCurrentMax = j;
                }
            }
        }
        // Print max of this subarray
        cout << " " << currentMax;
    }
    cout << '\n';
}

// From HackerRank
int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
