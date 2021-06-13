#include <vector>
// Find the minimum and maximum size of subsets given graph gb
// (Only counting subsets of size >= 2, not isolated nodes)

// Find the subset that node 'a' belongs to.
int Find(vector<int>& parent, int a) {
    if(parent[a] == -1) {
        return a;
    }
    else {
        parent[a] = Find(parent, parent[a]);
        return parent[a];
    }
}

// Union subsets & update sizes 
void Union(vector<int>& parent, vector<int>& size, int a, int b) {
    // Set a and b to be the roots of their subsets
    a = Find(parent, a); 
    b = Find(parent, b);
    // Only union/merge if a and b are in different subsets
    if(a != b) {
        parent[a] = b;
        size[b] += size[a];
        // Size vector stores the size of the subset at the index of the root
        // b is now the parent of a, so increment size at index b by size of a
    }
}

// Process graph gb with N edges
// which contains edges (a, b) with a in [1, N] and b in [N+1, 2N]
// (Note that nodes are 1-based)
// 
// Return minimum and maximum size of subsets
vector<int> componentsInGraph(vector<vector<int>> gb) {
    int edges = gb.size();
    int nodes = 2*edges;
    vector<int> disjoint_set (nodes, -1);
    vector<int> disjoint_set_size (nodes, 1); // Store size at root node index
    
    for(vector<int> edge : gb) {
        // convert from 1- to 0-based index
        int node1 = edge[0] - 1;
        int node2 = edge[1] - 1;
        Union(disjoint_set, disjoint_set_size, node1, node2);
    }
    
    // Initialize min and max to an impossible value (-1)
    int min = -1;
    int max = -1;
    for(int node : disjoint_set) {
        if(node != -1) {
            int root = Find(disjoint_set, node);
            int size = disjoint_set_size[root];
            // Set min and max to be 
            if(min == -1 || size < min)
                min = size;
            if(max == -1 || size > max)
                max = size;
        }
    }
    // Create vector containing min and max subset sizes & return
    vector<int> result {min, max};
    return result;
}