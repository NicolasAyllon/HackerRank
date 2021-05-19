#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Solution
long countTriplets(vector<long> arr, long r) {
    long triplets = 0;
    map<long, long> count_v; // map v => count of v's to right
    map<long, long> count_rv; // map v => count of rv's to right
    
    // iterate over arr from end to beginning
    for(int i = arr.size()-1; i >= 0; i--) {
        int v = arr[i];
        // increment triplets by number of rv's to right with r*rv to the right
        if(count_rv.find(r*v) != count_rv.end()) {
            triplets += count_rv[r*v];
        }
        // increment count_rv by count_v(rv) if rv is in count_v
        if (count_v.find(r*v) != count_v.end()) {
                if(count_rv.find(v) != count_rv.end())
                    count_rv[v] += count_v[r*v];
                else
                    count_rv[v] = count_v[r*v];
        }
        // increment count of v in count_v
        if (count_v.find(v) != count_v.end())
            count_v[v]++;
        else
            count_v[v] = 1;
    }
    return triplets; 
}


// From HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

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