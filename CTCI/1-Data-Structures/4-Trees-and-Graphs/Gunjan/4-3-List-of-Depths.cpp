#include<iostream>
#include<stdlib.h>
#include<vector>
#include<list>
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

binaryTree* generateBinaryTree(int treeDepth){
    if(treeDepth<=0) return NULL;
    // int Value = rand()%100;
    int Value = treeDepth;
    binaryTree* root = new binaryTree();
    root->data = Value;
    root->left =  generateBinaryTree(treeDepth-1);
    root->right = generateBinaryTree(treeDepth-1);
    return root;
}

void displayList(vector<list<binaryTree*>> listofLists){
    for(auto i:listofLists){
        for(binaryTree* j:i){
            cout << j->data << " -> ";
        }
        cout << endl;
    }
    return;
}

void listiFy(vector<list<binaryTree*>> &listofLists, binaryTree* root, int depth){
    if (!root) return;
    if(listofLists.size()<=depth){
        list<binaryTree*> temp;
        temp.push_back(root);
        listofLists.push_back(temp);
    } else {
        listofLists[depth].push_back(root);
    }
    listiFy(listofLists, root->left, depth+1);
    listiFy(listofLists, root->right, depth+1);
    return;
}

vector<list<binaryTree*>> listiFy(binaryTree* root){
    vector<list<binaryTree*>> listofLists;
    listiFy(listofLists,root,0);
    return listofLists;
}

int main(){
    int treeDepth = 5;
    binaryTree* tree = generateBinaryTree(treeDepth);
    displayTree(tree);
    cout << endl;
    displayList(listiFy(tree));
    return 0;
}