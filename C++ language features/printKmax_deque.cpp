#include <iostream>
#include <deque> 
using namespace std;

// Solution
void printKMax(int arr[], int n, int k){
    deque<int> Qi;
    int i;
    // first k indices (index 0 to k-1)
    for(i = 0; i < k; ++i) {
        // remove all indices from back of deque
        // with an element less than or equal to 
        // the one at index i being added
        while(!Qi.empty() && arr[Qi.back()] <= arr[i]) {
            Qi.pop_back();
        }
        Qi.push_back(i);
    }
    // The index at the front of the deque
    // has the max element of the first k elements, so print it
    cout << arr[Qi.front()];
    
    for(int i = k; i < n; ++i) {
        // remove elements outside the current window of length k
        while(!Qi.empty() && Qi.front() <= i - k) {
            Qi.pop_front();
        }
            
        // remove all indices from back of deque
        // with an element less than or equal to 
        // the one at index i being added
        while(!Qi.empty() && arr[Qi.back()] <= arr[i]) {
            Qi.pop_back();
        }
        Qi.push_back(i);
        // The index at the front of the deque has the max element
        // of the window from indices i-k+1 to i
        cout << " " << arr[Qi.front()];
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
