#include<iostream>
#include<unordered_map>
using namespace std;

class binaryTree{
    public:
    int data;
    binaryTree* left;
    binaryTree* right;
};

void display(binaryTree* root){
    if(root->left) display(root->left);
    cout << root->data << " ; ";
    if(root->right) display(root->right);
}

binaryTree* generateBinaryTree(int depth){
    if (!depth) return NULL;
    binaryTree* current = new binaryTree;
    current->data = depth;
    current->left = generateBinaryTree(depth-1);
    current->right = generateBinaryTree(depth-1);
    return current;
}

int pathsWithSum(binaryTree* root, int sum){

    return 0;
}

int main(){
    int depth = 5;
    int sum = 8;
    binaryTree* root = generateBinaryTree(depth);
    display(root); cout << endl;
    cout << "Number of paths that generates sum " << sum << " is : " << pathsWithSum(root,sum) << endl;
    return 0;
}