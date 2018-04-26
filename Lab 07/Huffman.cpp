#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;


// Create the node structure to represent a node for all encodings and dummy nodes
struct Node {
    Node * left;
    Node * right;
    double freq;
    char c;
    string code;
};


// Retrieves the minimum frequency value to combine. Rather than create a datastructure for the meanheap node, we will extract the min nodes through comparison
Node Min(vector<Node>& nArray) {

    int temp = INT_MAX;
    int pos;
    for(int i = 0; i < nArray.size(); i++) {
        if(temp > nArray[i].freq) {
            pos = i;
            temp = nArray[i].freq;
        }
    }
    Node tempNode = nArray[pos];
    nArray.erase(nArray.begin()+pos);

    return tempNode;
}

// Performs the huffman operation                   
Node huffman(vector<Node>& nArray) {

    while(nArray.size()>1) {       

        Node * rootNode = new Node;   
        Node * leftNode = new Node;
        Node * rightNode = new Node;

        *leftNode = Min(nArray);
        *rightNode = Min(nArray);
     
        rootNode->left = leftNode;
        rootNode->right = rightNode;
        rootNode->freq = leftNode->freq+rightNode->freq;
        
        nArray.push_back(*rootNode);
    }
    return nArray[0];
}

// Creates the encoding for each character
void encode(Node * temproot, string s, string arr[]) {
    Node * root = new Node;
    root = temproot;
  
    root->code = s;
    if(root->left != NULL || root->right != NULL) {
 
        root->left->code = s.append("0");
        s.erase(s.end()-1);
 
        root->right->code = s.append("1");
        s.erase(s.end()-1);

        encode(root->left, s.append("0"), arr);
        s.erase(s.end()-1);
      
        encode(root->right, s.append("1"), arr);        
        s.erase(s.end()-1);
    }
    else {
        int temp = root->c - 'A';
        arr[temp] = root->code;
    }
}

void printBinary(string* arr,int size) 
{
  for (int i = 0; i<size; i++) {
        cout << arr[i] << endl;
    }   
}

int main() {

    // initialize our vector of Nodes to hold our "tree"
    // the arr will hold each letter
    int size;
    cin >> size;
    string arr[10000];
    vector<Node> nArray; 

    for(int i = 0; i < size; i ++) 
    {
        Node node;
        char character;
        int charFrequency;
        cin >> charFrequency;
        character = 'A' + i;
        node.freq = charFrequency;
        node.c = character;
        node.left = NULL;
        node.right = NULL;

        nArray.push_back(node);
    }
    Node root = huffman(nArray);

    encode(&root, "", arr);

    printBinary(arr,size);

    return 0;
}
