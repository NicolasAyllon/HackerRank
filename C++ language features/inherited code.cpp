#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

// Solution
// Custom exception inherits from exception
class BadLengthException : public exception {
    private:
        int badLength; // store invalid length
    public:
        BadLengthException(int badLength) {
            this->badLength = badLength; // set invalid length
        }
    
        // Overload what() of the exception class
        const char* what() {
            // First convert int badLength to std::string
            // Then append .c_str() to get const char*
            return to_string(badLength).c_str();
        }
};

// From HackerRank

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}