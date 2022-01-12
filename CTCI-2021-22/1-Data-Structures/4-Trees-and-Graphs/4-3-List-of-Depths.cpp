#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<list>

using namespace std;


class TreeNode{
  public:
  int val;
  TreeNode* left;
  TreeNode* right;
};


TreeNode* generateBinaryTree(int depth){
  srand(time(0));
  if (depth<=0) {
    return NULL;
  }
  TreeNode* root = new TreeNode();
  // root->val = rand()%100;
  root->val = depth;
  root->left = generateBinaryTree(depth-1);
  root->right = generateBinaryTree(depth-1);
  return root;
}


void displayList(vector<list<TreeNode*>> nodeLists) {
  for(auto nodeList:nodeLists){
    for(auto node:nodeList){
      cout << node->val << ",";
    }
    cout << endl;
  }
}


void displayTree(TreeNode* root) {
  if (root==NULL){
    return;
  }
  displayTree(root->left);
  cout << root->val << ",";
  displayTree(root->right);
}


void listiFy(TreeNode* root, vector<list<TreeNode*>>& nodeLists, int depth) {
  if (root==NULL) {
    return;
  }
  if (nodeLists.size()<=depth) {
    list<TreeNode*> nodeList;
    nodeList.push_back(root);
    nodeLists.push_back(nodeList);
  } else {
    nodeLists[depth].push_back(root);
  }
  listiFy(root->left, nodeLists, depth+1);
  listiFy(root->right, nodeLists, depth+1);
  return;
}


vector<list<TreeNode*>> listiFy(TreeNode* root) {
  vector<list<TreeNode*>> nodeLists;
  listiFy(root, nodeLists, 0);
  return nodeLists;
}

int main(){
  int binaryTreeDepth = 5;
  TreeNode* root = generateBinaryTree(binaryTreeDepth);
  displayTree(root);
  cout << endl;
  displayList(listiFy(root));
  return 0;
}