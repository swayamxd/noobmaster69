#include<iostream>
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
    root->data = depth;
    root->left = generateBinaryTree(depth-1);
    root->right = generateBinaryTree(depth-1);
    return root;
}

// O(n) solution using O(1) space
// logic is, inorder traversal would spit increasing order sorted elements
// prev <= curr < next
int checkBST(binaryTree* root){
    if (!root) return -1;
    int leftNode, rightNode;
    leftNode = checkBST(root->left);
    if (leftNode==INT_MIN || root->data>leftNode) return INT_MIN;
    rightNode = checkBST(root->right);
    if (rightNode==INT_MIN || root->data<=rightNode) return INT_MIN;
    return 0;
}

int main(){
    int depth=5;
    binaryTree* tree = generateBinaryTree(depth);
    display(tree);
    cout << endl;
    (checkBST(tree)==INT_MIN) ? cout << "Not BST" << endl : cout << "BST" << endl;
    return 0;
}