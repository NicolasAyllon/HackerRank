// Solution:
// Decode a Huffman-encoded string
void decode_huff(node* root, string s) {
    // For readability, define null character
    char null_char = '\0';
    node* current = root;
    // Store resulting characters
    string result = "";
    
    // Read each character of string and 
    // follow edges in the tree to leaf nodes with characters
    for(int i = 0; i < s.size(); ++i) {
        // Follow edge to next node
        switch(s[i]) {
            case '0':
                current = current->left;
                break;
            case '1':
                current = current->right;
                break;
        }
        // If next node contains a character
        if(current->data != null_char) {
            // Add to result
            result += current->data;
            // Then reset current to root
            current = root;
        }
    }
    
    // Print result string
    std::cout << result;
}

/* Nodes of the Huffman tree are defined as:

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/