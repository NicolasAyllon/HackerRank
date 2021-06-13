#include <vector>
#include <iostream>

// Solution:
// Define class for Disjoint Set
// to support fast union & find operations
class DisjointSet {
    private:
    std::vector<int> m_parent;
    std::vector<int> m_size;
    
    public:
    // Constructor
    // Use vector of length vertices+1 for 1-based indices (index 0 is unused)
    DisjointSet(int vertices) 
        : m_parent(vertices+1, -1), m_size(vertices+1, 1) {}
        // Note:
        // m_parent is initialized to [-1,-1,-1,...]
        // meaning nodes starts with no parent, as root nodes
        //
        // m_size is initialized to [1,1,1,...]
        // meaning each node is in a subset of size 1, containing just itself
        // After union, m_size stores the size of the subset 
        // at the index of the root node.
    
    // Determine root of subset node at this index belongs to
    int find(int index) {
        if(m_parent[index] == -1) {
            return index;
        } else {
            return find(m_parent[index]);
        }
    }
    
    // Return size of subset node at index belongs to
    int subset_size(int index) {
        return m_size[find(index)];
    }
    
    // Merge two subsets by connecting nodes at indices a and b
    void Union(int index_a, int index_b) {
        int root_a = find(index_a);
        int root_b = find(index_b);
        
        if(root_a != root_b) {
            if(m_size[root_a] < m_size[root_b]) {
                m_parent[root_a] = root_b;
                m_size[root_b] += m_size[root_a];
            }
            // Otherwise, m_size[root_a] >= m_size[root_b]
            else {
                m_parent[root_b] = root_a;
                m_size[root_a] += m_size[root_b];
            }
        }
    }
};


// Process n nodes with q queries to
//   - connect two nodes (indices i and j) 
//   - print the current subset size of a node (index i)
int main() { 
    int n, q;
    std::cin >> n >> q;
    DisjointSet network(n);
    // In the context of the question, this represents a social network
    
    char query_type;
    int i, j;
    while(q--) {
        std::cin >> query_type;
        switch(query_type) {
            // Merge nodes i and j
            case 'M':
                std::cin >> i >> j;
                network.Union(i, j);
                break;
            // Print subset size for node i
            case 'Q':
                std::cin >> i;
                std::cout << network.subset_size(i) << '\n';
                break;
            default:
                std::cout << "Error: unknown query type " << query_type << '\n';
                break;
        }
    }
    return 0;
}