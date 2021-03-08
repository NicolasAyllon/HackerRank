#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Solution
// Given an unordered array containing integers 1 to n, return the minimum number of swaps required to sort the array {1, 2, 3, ..., n}
int minimumSwaps(vector<int> arr) {
    int swaps = 0;
    int i = 0;
    int lastIndex = arr.size() - 1;
    
    while(i <= lastIndex) {
        // element is already in correct place
        if(arr[i] == i + 1) {
            i++;
        }
        // element arr[i] (ex. 8) is not in correct place, it should be at index arr[i] - 1 (ex. 7)
        else {
            //indices to swap
            int a = i;
            int b = arr[i] - 1;
            // swap element to put it in correct place
            int temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
            
            swaps++;
            // don't increment i because the element now at the current index may not be in order
        }
    }
    return swaps;
}



// From HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

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
