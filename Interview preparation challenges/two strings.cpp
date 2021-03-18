#include <bits/stdc++.h>

using namespace std;

// Solution
// 1-character substrings count, so it is sufficient 
// to check whether s_2 contains any letters in s_1.
string twoStrings(string s1, string s2) {
    const int num_letters_in_alphabet = 26;
    
    // Store s1's letters in a set
    set<char> letters_in_s1;
    for(int i = 0; i < s1.length(); i++) {
        // insert() adds each letter to the set
        // and does nothing if already in the set
        letters_in_s1.insert(s1[i]);
        
        // If all letters in the alphabet have appeared
        // we can safely break from the loop.
        if(letters_in_s1.size() == num_letters_in_alphabet) break;
    }
    
    // For each letter in s2, see whether it's in the set of s1's letters
    for(int i = 0; i < s2.length(); i++) {
        // We found the current letter in the set of s1's letters
        if(letters_in_s1.find(s2[i]) != letters_in_s1.end()) {
            return "YES";
        }
    }
    // No letters in s2 matched any of s1's.
    return "NO";
}

// From HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
