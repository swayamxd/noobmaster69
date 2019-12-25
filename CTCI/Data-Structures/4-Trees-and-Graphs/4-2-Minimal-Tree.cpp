#include<iostream>
#include<vector>
using namespace std;

class BST{
public:
    int data;
    BST* left;
    BST* right;
};

void display(BST* root){
    if(root){
        display(root->left);
        cout << root->data << " ; ";
        display(root->right);
    }
    return;
}

// O(n) solution with inorder traversal
// applied binary search while creating bottom up BST
// top down approach could have taken O(n*log(n)) solution
BST* bstFy(vector<int>nodeList,int low,int high){
    if(high<low) return NULL;
    if(high==low) {
        BST* leafNode = new BST();
        leafNode->data = nodeList[high];
        leafNode->left=NULL;
        leafNode->right=NULL;
        return leafNode;
    }
    int mid = (low+high)/2;
    BST *rootNode = new BST();
    rootNode->data = nodeList[mid];
    rootNode->left = bstFy(nodeList,low,mid-1);
    rootNode->right = bstFy(nodeList,mid+1,high);
    return rootNode;
}

BST* bstFy(vector<int> nodeList){
    return bstFy(nodeList,0,nodeList.size()-1);
}

int main(){
    vector<int> nodeList;
    cout << "Entered sorted data :" << endl;
    for(int i=0;i<10;i++){
        cout << i << " ; ";
        nodeList.push_back(i);
    }
    cout << endl << "In-Order traversal of BST :" << endl;
    display(bstFy(nodeList));
    cout << endl;
    return 0;
}