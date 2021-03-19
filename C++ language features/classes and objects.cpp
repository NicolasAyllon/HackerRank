#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Solution 
class Student {
    private:
        int scores[5]; // int array to hold 5 scores
    
    public:
        // Read 5 integers and store in scores array
        void input() {
            int score;
            for(int i = 0; i < 5; i++) {
                cin >> score;
                scores[i] = score;
            }
        }
        
        // Return the sum of all scores in the scores array    
        int calculateTotalScore() {
            int sum;
            for(int i = 0; i < 5; i++) {
                sum += scores[i];
            }
            return sum;
        }
};

// From HackerRank
int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
