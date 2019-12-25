#include<iostream>
#include<stdlib.h>
#include<limits.h>
#include<vector>
using namespace std;

class binaryTree{
public:
    int data;
    binaryTree* left;
    binaryTree* right;
};

void display(binaryTree* root){
    if(!root) return;
    display(root->left);
    cout << root->data << " ; ";
    display(root->right);
    return;
}

binaryTree* generateBinaryTree(int depth){
    if(depth<=0) return NULL;
    binaryTree* root = new binaryTree();
    // root->data = depth;
    root->data = rand()%100;
    root->left = generateBinaryTree(depth-1);
    root->right = generateBinaryTree(depth-1);
    return root;
}

// O(n) solution using O(1) space
// logic is, inorder traversal would spit increasing order sorted elements
// prev <= curr < next
bool checkBST(binaryTree* root, int min, int max){
    if(!root) return true;
    if(max<=root->data || min>root->data) return false;
    if (!checkBST(root->left,min,root->data) || !checkBST(root->right,root->data,max)) return false;
    return true;
}

bool checkBST(binaryTree* root){
    return checkBST(root, INT_MIN, INT_MAX);
}

int main(){
    int depth=5;
    binaryTree* tree = generateBinaryTree(depth);
    display(tree);
    cout << endl;
    (checkBST(tree)) ? cout << "BST" << endl : cout << "Not BST" << endl;
    return 0;
}