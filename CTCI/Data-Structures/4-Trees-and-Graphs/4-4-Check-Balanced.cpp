#include<iostream>
#include<stdlib.h>
#define max(a,b)((a>b) ? a : b)
#define abs(a) ((a<0) ? -a : a)
using namespace std;

class binaryTree{
public:
    int data;
    binaryTree* left;
    binaryTree* right;
};

void displayTree(binaryTree* root){
    if(root){
        displayTree(root->left);
        cout << root->data << " ; ";
        displayTree(root->right);
    }
    return;
}

binaryTree* generateUnbalanced(binaryTree* root){
    binaryTree * newTree = root;
    newTree->left = root->right->right->left;
    return newTree;
}

binaryTree* generateBinaryTree(int treeDepth){
    if(treeDepth<=0) return NULL;
    int Value = rand()%100;
    // int Value = treeDepth;
    binaryTree* root = new binaryTree();
    root->data = Value;
    root->left =  generateBinaryTree(treeDepth-1);
    root->right = generateBinaryTree(treeDepth-1);
    return root;
}

// O(n) solution by finding height simultaneously
int check(binaryTree* root){
    if(!root) return 0;
    int leftHeight = check(root->left);
    if (leftHeight==INT16_MIN) return INT16_MIN;
    int rightHeight = check(root->right);
    if (rightHeight==INT16_MIN) return INT16_MIN;
    int heightDifference = abs(leftHeight-rightHeight);
    // pass max of left or right height else error code
    return (heightDifference<2) ? max(leftHeight,rightHeight)+1 : INT16_MIN;
}

bool checkBalanced(binaryTree* root){
    return (check(root)==INT16_MIN) ? false : true;
}

/*
// O(n*log(n)) solution as getHeight is getting called for n times
int getHeight(binaryTree* root){
    if(!root) return 0;
    return max(getHeight(root->left),getHeight(root->right))+1;
}
bool checkBalanced(binaryTree* root){
    if(!root) return true;
    int heightDifference = getHeight(root->left)-getHeight(root->right);
    if (abs(heightDifference)<2 && checkBalanced(root->left) && checkBalanced(root->right)) return true;
    return false;
}
*/

int main(){
    int treeDepth = 5;
    binaryTree* tree = generateBinaryTree(treeDepth);
    displayTree(tree);
    cout << endl;
    tree = generateUnbalanced(tree);
    displayTree(tree);
    cout << endl;
    (checkBalanced(tree)) ? cout << "Balanced" << endl : cout << "Unbalanced" << endl;
    return 0;
}