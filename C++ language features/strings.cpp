#include <iostream>
#include <string>
using namespace std;

int main() {
    
	// Declare strings and read input
    string a;
    string b;
    cin >> a >> b;
    
    // Create string a_2 to match a but with b's first character
    // Create string b_2 to match b but with a's first character
    string a_2 = a;
    string b_2 = b;
    a_2[0] = b[0]; // change a_2's first character to b's
    b_2[0] = a[0]; // change b_2's first character to a's
    
    // print lengths, concatenation, and a_2 b_2 on separate lines
    cout << a.size() << " " << b.size() << endl;
    cout << a + b << endl;
    cout << a_2 << " " << b_2 << endl;
    
    return 0;
}
