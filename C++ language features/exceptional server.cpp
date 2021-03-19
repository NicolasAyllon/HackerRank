#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;
		
        // Solution
        int result;
        try {
            Server server;
            result = server.compute(A, B);
            cout << result << '\n'; 
        }
        // Most specific exception first
        catch (bad_alloc& ba) {
            cout << "Not enough memory" << '\n';
        }
        // Less specific: any standard exception
        catch (exception& e) {
            cout << "Exception: " << e.what() << '\n';
        }
        // Anything else: nonstandard exception
        catch (...) {
            cout << "Other Exception" << '\n';
        }
	}