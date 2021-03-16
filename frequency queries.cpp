#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Solution
// Use 2 maps: one to track frequency of a given element, 
// and one to track how many distinct elements have a certain frequency
vector<int> freqQuery(vector<vector<int>> queries) {
    vector<int> results;
    // store the result of type-3 queries as 0s and 1s
    map<int, int> lookup_frequency; 
    // map: value -> frequency
    map<int, int> lookup_occurences;
    // map: frequency -> number of distinct elements with given frequency
    
    for(vector<int> query : queries) {
        // Operation 1: insert the following element
        if(query[0] == 1) {
            int elementToInsert = query[1];
            if(lookup_frequency.find(elementToInsert) != lookup_frequency.end()) {
                int currentFrequency = lookup_frequency[elementToInsert];
                lookup_frequency[elementToInsert]++;
                
                // decrease count of elements with frequency currentFrequency
                lookup_occurences[currentFrequency]--;
                // increase count of elements with frequency currentFrequency+1
                if (lookup_occurences.find(currentFrequency+1) != lookup_occurences.end())
                    lookup_occurences[currentFrequency+1]++;
                else
                    lookup_occurences[currentFrequency+1] = 1;
            }
            else {
                lookup_frequency[elementToInsert] = 1;
                lookup_occurences[1]++; // new element, increase occurences of frequency 1
            } 
        }
        
        // Operation 2: delete the following element
        else if(query[0] == 2) {
            int elementToDelete = query[1];
            if(lookup_frequency.find(elementToDelete) != lookup_frequency.end()) {
                if(lookup_frequency[elementToDelete] > 0) {
                    int currentFrequency = lookup_frequency[elementToDelete];
                    lookup_frequency[elementToDelete]--;
                    // decrease count of elements with frequency currentFrequency
                    if(lookup_occurences[currentFrequency] > 0)
                        lookup_occurences[currentFrequency]--;
                    // increase count of elements with frequency currentFrequency-1
                    // Note: there is no need to check whether frequency-1 -> occurences is in the map 
                    // because it was created at a previous time when that was true (now it is again).
                    lookup_occurences[currentFrequency-1]++;
                }
            }
        }
        
        // Operation 3: check whether there is at least 1 element with the following frequency. Put 1 = yes or 0 = no into the results vector.
        else if(query[0] == 3) {
            int desiredFrequency = query[1];
            bool found = false;
            if(lookup_occurences.find(desiredFrequency) != lookup_occurences.end()) {
                if(lookup_occurences[desiredFrequency] > 0) {
                    found = true;
                }
            }
            
            if(found) 
                results.push_back(1); // put 1 = yes in results vector
            else
                results.push_back(0); // put 0 = no in results vector
        }
    }
    return results;
}

// From HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
