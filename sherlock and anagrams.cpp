#include <bits/stdc++.h>

using namespace std;

void map_increment(char c, map<char, int> &m); // helping method 1
void map_decrement(char c, map<char, int> &m); // helping method 2

// Solution
int sherlockAndAnagrams(string s) {
    int L = s.length();
    map<char, int> fixed_window;
    map<char, int> sliding_window_1;
    map<char, int> sliding_window_2;
    int substr_length;
    int anagrams = 0;
    
    for(int i = 0; i <= L-2; i++) {
        // construct histogram for substring of first i+1 chars
        substr_length = i+1;
        map_increment(s[i], fixed_window); // first i+1 chars

        for(int j = i; j <= L-2; j++) {
            if(j == i) {
                // copy fixed window of first i+1 chars
                sliding_window_1 = fixed_window;
            }
            else{
                // advance sliding window 1 to the right
                map_increment(s[j], sliding_window_1);
                map_decrement(s[j-substr_length], sliding_window_1);
                sliding_window_2 = sliding_window_1;
            }
            
            // copy sliding_window_1 to sliding_window_2
            sliding_window_2 = sliding_window_1;
            
            // advance sliding window 2 to the right and compare to window 1
            for(int k = j+1; k <= L-1; k++) {
                map_increment(s[k], sliding_window_2);
                map_decrement(s[k-substr_length], sliding_window_2);
            
                if(sliding_window_2 == sliding_window_1) {
                    anagrams++;
                }
            }
        }
    }
    return anagrams;
}

// Helping method increments char count, or inserts new char with count = 1
void map_increment(char c, map<char, int> &m) {
    if(m.find(c) != m.end()) {
        m[c]++;
    }
    else {
        m[c] = 1;
    }
}

// Helping method to decrement char count, or erases char if count = 0
void map_decrement(char c, map<char, int> &m) {
    if(m[c] > 1) {
        m[c]--;
    }
    else {
        m.erase(m.find(c));
    }
}

// Debug
// void print_map(map<char, int> m) {
//     for(auto it = m.begin(); it != m.end(); it++) {
//         cout << it->first << " => " << it->second << endl;
//     }
//     cout << endl;
// }


// From HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
