#include<iostream>
#include<stdlib.h>
using namespace std;

class binaryTree{
public:
    int data;
    binaryTree* root;
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

binaryTree* generateBinaryTree(binaryTree* root, int depth){
    if(depth<=0) return NULL;
    binaryTree* current = new binaryTree();
    // current->data = depth;
    current->data = rand()%100;
    current->root = root;
    current->left = generateBinaryTree(current, depth-1);
    current->right = generateBinaryTree(current, depth-1);
    return current;
}

binaryTree* inOrderSuccessor(binaryTree* node){
    // if node is NULL itself
    if (!node) return NULL;
    // if right subtree exists
    if (node->right) {
        while(node->left){
            node = node->left;
        }
        return node;
    }
    // if right subtree doesn't exist
    else {
        binaryTree* child = node;
        binaryTree* parent = node->root;
        while(parent && parent->right!=child){
            child = child->root;
            parent = parent->root;
        }
        return parent;
    }
    return NULL;
}

int main(){
    int depth=5;
    binaryTree* tree = generateBinaryTree(NULL, depth);
    display(tree);
    cout << endl;
    binaryTree* successor = inOrderSuccessor(tree->left->right->left);
    // binaryTree* successor = inOrderSuccessor(NULL);
    (successor) ?
        cout << successor << " -> " << successor->data << endl :
        cout << "No successor found" << endl;
    return 0;
}