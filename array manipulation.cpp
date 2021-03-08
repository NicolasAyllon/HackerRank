#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Solution
long arrayManipulation(int n, vector<vector<int>> queries) {
    long int* differentials = new long int[n+1]();
    // Create array of size n+1 of all 0s
    // with unused 0th element to follow 1-based indices in question
    // This array will hold the finite differences of the actual array (arr)
    // differentials[i] = arr[i] - arr[i-1] (where differentials[0] = 0)
    long int firstIndex = 0;
    long int lastIndex = 0;
    long int numberToAdd = 0;
    
    for(int i = 0; i < queries.size(); i++) {
        firstIndex = queries[i][0];
        lastIndex = queries[i][1];
        numberToAdd = queries[i][2];
        
        // increase differential from arr[firstIndex-1] to arr[firstIndex] by numberToAdd
        differentials[firstIndex] += numberToAdd; 
        
        // decrease differential from arr[lastIndex] to arr[lastIndex + 1] by numberToAdd
        // (only if lastIndex + 1 is in bounds <= n)
        if(lastIndex + 1 <= n) {
            differentials[lastIndex + 1] -= numberToAdd;    
        }
    }
    
    // Find maximum
    long int currentElementInActualArray = 0;
    long int max = 0;
    for(int i = 1; i <= n; i++) {
        // telescoping sum:
        // d_1 + d_2 + d_3 + ... + d_i
        // (a_1 - a_0) + (a_2 - a_1) + (a_3 - a_2) + ... + (a_i - a_i-1)
        // a_i - a_0 
        // but the first (extra) slot in a is a_0 = 0
        // a_i
        currentElementInActualArray += differentials[i];
        if(currentElementInActualArray > max) {
            max = currentElementInActualArray;
        }
    }
    return max;
}


// From HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
