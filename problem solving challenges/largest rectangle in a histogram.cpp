#include <stack>
#include <cmath>

using namespace std

long largestRectangle(vector<int> h) {
    h.push_back(0); 
    // add 0 to end of vector to perform final iteration without while loop
    stack<pair<int,int>> s; // first: position // second: height
    int maxArea = 0;
    
    for(int i = 0; i < h.size(); ++i) {
        // this bar is shorter than top of stack's
        int minIndex = i;
        // Calculate areas of all rectangles cut off by this bar
        // and track how far back the current bar can extend
        while(!s.empty() && h[i] < s.top().second) {
            minIndex = s.top().first; 
            // track minimum index with height greater than h[i]
            int height = s.top().second;
            int width = i - s.top().first;
            int rectangleArea = width*height;
            maxArea = max(maxArea, rectangleArea);
            s.pop();
        }
        // this bar is taller than one at top of stack's
        if(s.empty() || h[i] > s.top().second) {
            pair<int,int> p(minIndex, h[i]);
            s.push(p);
        }
    }
    return maxArea;
}