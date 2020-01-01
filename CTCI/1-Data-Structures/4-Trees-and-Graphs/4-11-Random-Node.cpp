#include<iostream>
using namespace std;

class binaryTree{
    int data;
    int size=0;
    binaryTree* left;
    binaryTree* right;
    binaryTree* treeNode(int data){
        binaryTree* root = new binaryTree();
        root->data = data;
        root->left=NULL;
        root->right=NULL;
        size++;
        return root;
    }
    public:
    void insert(int data){
        if(!this)
        if(this->data<data) (*(this)->right).insert(data);
        if(this->data>=data) (*(this)->left).insert(data);
    }

};

int main(){

    return 0;
}