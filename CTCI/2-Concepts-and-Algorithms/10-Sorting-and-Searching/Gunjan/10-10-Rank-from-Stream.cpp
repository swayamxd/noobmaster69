#include<iostream>
using namespace std;

class BST{
    struct node{
        int data;
        int leftNodeCount;
        node *left;
        node *right;
    };
    node *root;
    node *insert(node* root, int data){
        if(root==NULL){
            root = new node;
            root->data = data;
            root->left = NULL;
            root->right = NULL;
            root->leftNodeCount = 0;
        }
        else if(root->data > data){
            root->leftNodeCount++;
            root->left = insert(root->left,data);
        }
        else root->right = insert(root->right,data);
        return root;
    }
    int findLesserCount(node* root, int key, int count){
        if(root==NULL) return -1;
        else if(root->data == key) return count+root->leftNodeCount;
        else if(root->data > key) return findLesserCount(root->left,key,count);
        else return findLesserCount(root->right,key,(count+root->leftNodeCount));
    }
    void display(node* root){
        if(root->left) display(root->left);
        cout << root->data << " ; ";
        if(root->right) display(root->right);
    }
    node* makeEmpty(node* root){
        if(root){
            makeEmpty(root->left);
            makeEmpty(root->right);
            delete root;
        }
        return NULL;
    }
public:
    BST() {
        root = NULL;
    }
    ~BST() {
        root = makeEmpty(root);
    }
    void insert(int data){
        root = insert(root,data);
    }
    int find(int key){
        return findLesserCount(root,key,0);
    }
    void display(){
        display(root);
        cout << endl;
    }
};

void generateRandomBST(BST &newBST,int BSTlength){
    while(--BSTlength){
        newBST.insert(BSTlength);
    }
}

int main(){
    int BSTlength = 10;
    BST newBST;
    generateRandomBST(newBST,BSTlength);
    int key = rand()%BSTlength;
    newBST.display();
    int leftNodeCount = newBST.find(key);
    (leftNodeCount>=0) ?
        cout << key << " has total " << leftNodeCount << " smaller items" << endl :
        cout << key << " not found." << endl ;
    return 0;
}