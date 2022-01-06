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
  if(root==NULL){
    return;
  }
  display(root->left);
  cout << root->data << " -> ";
  display(root->right);
}

BST* BSTfy(vector<int> nodeList, int low, int high){
  if(low>high) {
    return NULL;
  }
  int mid = low+(high-low)/2;
  BST* bst = new BST();
  bst->data = nodeList[mid];
  bst->left = BSTfy(nodeList, low, mid-1);
  bst->right = BSTfy(nodeList, mid+1, high);
  return bst;
}

BST* BSTfy(vector<int> nodeList){
  return BSTfy(nodeList, 0, nodeList.size()-1);
}

int main(){
  vector<int> nodeList;
  for(int i=0;i<10;i++){
    nodeList.push_back(i);
  }
  BST* bst = BSTfy(nodeList);
  display(bst);
  return 0;
}