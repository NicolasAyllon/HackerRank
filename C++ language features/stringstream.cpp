#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

// Solution
vector<int> parseInts(string str) {
    stringstream ss; // create new stringstream
    ss.str(str); // set contents to str
    
    vector<int> arr;
    int numberToAdd;
    char ch; // storage area for commas
    
    // Extract integer from string into numberToAdd and push onto array
    // Operator >> returns a value so the statement is true
	while(ss >> numberToAdd) {
        arr.push_back(numberToAdd);
        ss >> ch; // read comma if available
    }
    return arr;
}

// From HackerRank
int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    return 0;
}