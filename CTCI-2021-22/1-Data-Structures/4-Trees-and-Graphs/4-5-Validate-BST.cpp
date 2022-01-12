#include <iostream>

using namespace std;

class TreeNode{
  public:
  int val;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* generateBinaryTree(int depth){
  if (!depth) return NULL;
  TreeNode* root = new TreeNode();
  root->val = depth;
  root->left = generateBinaryTree(depth-1);
  root->right = generateBinaryTree(depth-1);
  return root;
}

void display(TreeNode* root){
  if (root==NULL) return;
  display(root->left);
  cout << root->val << ",";
  display(root->right);
  return;
}

bool isBST(TreeNode* root, int minVal, int maxVal){
  if(root==NULL){
    return true;
  }
  if (!(minVal <= root->val) || !(root->val < maxVal)){
    return false;
  }
  return (isBST(root->left, minVal, root->val) && isBST(root->right, root->val, maxVal));
}

bool isBST(TreeNode* root){
  return isBST(root, INT32_MIN, INT32_MAX);
}

int main(){
  int depth = 5;
  TreeNode* root = generateBinaryTree(depth);
  display(root);
  cout << endl;
  cout << (isBST(root)? "BST" : "Not BST") << endl;
  return 0;
}