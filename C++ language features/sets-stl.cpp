#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int q; // number of queries
    int query_type; // 1, 2, or 3
    int x; // number that the query is about
    set<int> s; // set of ints
    
    // Read in number of queries
    cin >> q;
    for(int i = 0; i < q; ++i) {
        cin >> query_type >> x;
        
        switch(query_type) {
            // Type 1: insert element
            case 1:
                s.insert(x);
                break;
            // Type 2: erase element
            case 2:
                // erase() does nothing is the element x isn't in the set
                s.erase(x);
                break;
            // Type 3: print whether element is in the set
            case 3:
                if(s.find(x) != s.end()) {
                    cout << "Yes" << '\n';
                }
                else {
                    cout << "No" << '\n';
                }
                break;
            default:
                cout << "unknown query type: " << query_type << '\n';
        }
    }
    return 0;
}