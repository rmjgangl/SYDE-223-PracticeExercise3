#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

class BST {
protected:
    struct BSTNode {
        int key;
        BSTNode* left;
        BSTNode* right;
        BSTNode(int new_key) : key(new_key), left(NULL), right(NULL) {}
    };
    BSTNode* root;
public:
    BSTNode** vec;
    BSTNode* create_minimal_BST(vector<int> vector_a);
    BSTNode* sort(int start, int end, vector<int> vector_b);
    void print();
    vector<int> my_vec;
};

BST::BSTNode* BST::create_minimal_BST(vector<int> vector_c) {
    int first = vector_c[0];
    int last = vector_c[vector_c.size() - 1];
    return sort(first , last, vector_c);
}

void BST::print() {
    queue<BSTNode*> B;
    
    cout << "Start Breadth-First Traversal:" << endl;
    while (!B.empty()) {
        BSTNode *cur = B.front();
        cout << cur->key << " "; // visit the current node
        if (cur->left) B.push(cur->left); // enqueue left
        if (cur->right) B.push(cur->right); // enqueue right
        B.pop();
    }
    cout << endl;
}

BST::BSTNode* BST::sort(int start, int end, vector<int> vector_d) {
    if (start > end)
        return NULL;
    
    int mid = (start + end) / 2;
    
    BSTNode* Node = new BSTNode(vector_d[mid]);
    Node->left = sort(start, mid - 1, vector_d);
    Node->right = sort(mid + 1, end, vector_d);
    
    return Node;
}

int main () {
    BST b;
    vector<int> my_vec = {1,2,3,4,5,6,7};
    b.create_minimal_BST(my_vec);
    b.print();
}
