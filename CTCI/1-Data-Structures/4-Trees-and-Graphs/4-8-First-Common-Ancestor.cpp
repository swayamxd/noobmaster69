#include<iostream>
using namespace std;

class binaryTree{
    public:
    int data;
    binaryTree* left;
    binaryTree* right;
};

void display(binaryTree* root){
    if (!root) return;
    cout << root->data << " ; ";
    display(root->left);
    display(root->right);
}

binaryTree* generateBinaryTree(int depth){
    if(depth<=0) return NULL;
    binaryTree* root = new binaryTree();
    root->data = depth;
    root->left = generateBinaryTree(depth-1);
    root->right = generateBinaryTree(depth-1);
    return root;
}

// checks if an element is present in the tree
bool check(binaryTree* root, binaryTree* x){
    if(root==NULL) return false;
    if(root==x) return true;
    return(check(root->left,x) || check(root->right,x));
}

// O(n) solution using recursion
binaryTree* firstCommonAncestor(binaryTree* root, binaryTree* p, binaryTree* q){

    // if p and q are in different subtree, then current node is the common ancestor node
    if ((check(root->left,p) && check(root->right,q)) || (check(root->right,p) && check(root->left,q)))
        return root;

    // if p and q both are in left subtree, then the common ancestor node also lies in the left subtree
    if (check(root->left,p) && check(root->left,q))
        return firstCommonAncestor(root->left,p,q);

    // if p and q both are in right subtree, then the common ancestor node also lies in the right subtree
    if (check(root->right,p) && check(root->right,q))
        return firstCommonAncestor(root->right,p,q);

    // if either p or q not found, return NULL, as no ancestor can be found
    return NULL;
}

int main(){
    int depth = 5;
    binaryTree* root = generateBinaryTree(depth);
    display(root);
    cout << endl;
    binaryTree* ancestor = firstCommonAncestor(root,root->left->left,root->left->right);
    ancestor ?
        cout << root->left->data << " : " << ancestor->data << endl :
        cout << "No common ancestor found" << endl;
    return 0;
}