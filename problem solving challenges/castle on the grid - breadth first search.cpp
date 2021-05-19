#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

bool inBounds(int row, int col, int Rows, int Cols);

void explore (int row, int col, int Rows, int Cols, 
    vector<vector<bool>>& passable, vector<vector<bool>>& visited,
    vector<pair<int,int>>& pairsToExplore);
void exploreNorth (int row, int col, int Rows, int Cols, 
    vector<vector<bool>>& passable, vector<vector<bool>>& visited,
    vector<pair<int,int>>& pairsToExplore);
void exploreEast (int row, int col, int Rows, int Cols, 
    vector<vector<bool>>& passable, vector<vector<bool>>& visited, 
    vector<pair<int,int>>& pairsToExplore);
void exploreSouth (int row, int col, int Rows, int Cols, 
    vector<vector<bool>>& passable, vector<vector<bool>>& visited,
    vector<pair<int,int>>& pairsToExplore);
void exploreWest (int row, int col, int Rows, int Cols, 
    vector<vector<bool>>& passable, vector<vector<bool>>& visited, vector<pair<int,int>>& pairsToExplore);

// row and col are 0-based indices
// Rows and Cols are the total numbers of rows and columns in the grid
bool inBounds(int row, int col, int Rows, int Cols) {
    return (0 <= row) && (row < Rows) && (0 <= col) && (col < Cols);
}

void exploreNorth(int row, int col, int Rows, int Cols, 
    vector<vector<bool>>& passable, vector<vector<bool>>& visited,
    vector<pair<int,int>>& pairsToExploreNext) {
    while(inBounds(row, col, Rows, Cols) && passable[row][col]) {
        if(!visited[row][col]) {
            pair<int,int> unexploredPair(row, col);
            pairsToExploreNext.push_back(unexploredPair);
        }
        --row; // Decrease rows (move North)
    }
}

void exploreEast(int row, int col, int Rows, int Cols, 
    vector<vector<bool>>& passable, vector<vector<bool>>& visited,
    vector<pair<int,int>>& pairsToExploreNext) {
    while(inBounds(row, col, Rows, Cols) && passable[row][col]) {
        if(!visited[row][col]) {
            pair<int,int> unexploredPair(row, col);
            pairsToExploreNext.push_back(unexploredPair);
        }
        ++col; // Increase cols (move East)
    }
}

void exploreSouth(int row, int col, int Rows, int Cols, 
    vector<vector<bool>>& passable, vector<vector<bool>>& visited,
    vector<pair<int,int>>& pairsToExploreNext) {
    while(inBounds(row, col, Rows, Cols) && passable[row][col]) {
        if(!visited[row][col]) {
            pair<int,int> unexploredPair(row, col);
            pairsToExploreNext.push_back(unexploredPair);
        }
        ++row; // Increase rows (move South)
    }
}

void exploreWest(int row, int col, int Rows, int Cols, 
    vector<vector<bool>>& passable, vector<vector<bool>>& visited,
    vector<pair<int,int>>& pairsToExploreNext) {
    while(inBounds(row, col, Rows, Cols) && passable[row][col]) {
        if(!visited[row][col]) {
            pair<int,int> unexploredPair(row, col);
            pairsToExploreNext.push_back(unexploredPair);
        }
        --col; // Increase cols (move East)
    }
}

void explore(int row, int col, int Rows, int Cols, 
    vector<vector<bool>>& passable, vector<vector<bool>>& visited,
    vector<pair<int,int>>& pairsToExploreNext) {

    exploreNorth(row, col, Rows, Cols, passable, visited, pairsToExploreNext);
    exploreEast(row, col, Rows, Cols, passable, visited, pairsToExploreNext);
    exploreSouth(row, col, Rows, Cols, passable, visited, pairsToExploreNext);
    exploreWest(row, col, Rows, Cols, passable, visited, pairsToExploreNext);
}


// Main Function
// *************
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    // get dimensions
    int Rows = grid.size();
    int Cols = grid[0].size();
    
    vector<vector<int>> steps; // number of steps required to reach space
    vector<vector<bool>> visited; // true if visited or in queue, false if unvisited
    vector<vector<bool>> passable; // true if open path '.', false if blocked 'X'
    
    // construct grid from vector<string>
    for(string char_grid_row: grid) {
        // Create row of 0's and push onto steps
        vector<int> steps_row(Cols, 0); // number of steps required to reach space
        steps.push_back(steps_row);
        // Create row of false values and push onto visited
        vector<bool> visited_row(Cols, false);
        visited.push_back(visited_row);
        // Create row of bools from grid (where '.' = true and 'X' = false)
        vector<bool> passable_row;
        for(char c: char_grid_row) {
            if(c == '.') { passable_row.push_back(true); }
            // c == 'X'
            else { passable_row.push_back(false); }
        }
        passable.push_back(passable_row);
    }
    /*
    axes
        \----- y
        \
        \
        x
    */
    int start_row = startX; // x is row
    int start_col = startY; // y is column
    int goal_row = goalX;
    int goal_col = goalY;
    
    queue<pair<int,int>> q;
    pair<int,int> start(start_row, start_col);
    q.push(start);
    
    while(!q.empty()) {
        vector<pair<int,int>> pairsToExploreNext;
        int current_row = q.front().first;
        int current_col = q.front().second;
        int current_steps = steps[current_row][current_col];
        // variables for exploring (exp) squares directly N, E, S, W
        int exp_row = current_row;
        int exp_col = current_col;
        // march north, east, south, and west
        // The following functions fill the vector pairsToExploreNext
        // explore until reaching edge of grid or encountering block 'X'
        // if unvisited add to queue
        explore(current_row, current_col, Rows, Cols, passable, visited, pairsToExploreNext);
        
        for(auto pairToExplore : pairsToExploreNext) {
            // push onto queue
            q.push(pairToExplore);
            // mark as visited-or-in-queue
            visited[pairToExplore.first][pairToExplore.second] = true;
            // mark steps as this square's steps + 1
            steps[pairToExplore.first][pairToExplore.second] = current_steps+1;
            // immediately return steps if goal has been discovered
            if(pairToExplore.first == goal_row && pairToExplore.second == goal_col) {
                return steps[pairToExplore.first][pairToExplore.second];
            }
        }
        // pop this square off queue
        q.pop();
    }
    // The queue is empty and the goal still hasn't been reached
    // This means the goal is unreachable, so return -1.
    return -1;
}