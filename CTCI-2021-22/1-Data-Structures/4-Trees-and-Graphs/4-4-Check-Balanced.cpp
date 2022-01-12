#include<iostream>
#include<math.h>

using namespace std;

class TreeNode{
  public:
  int val;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* generateBinaryTree(int depth){
  if(depth<=0) {
    return NULL;
  }
  TreeNode* root = new TreeNode();
  root->val = depth;
  root->left = generateBinaryTree(depth-2);
  root->right = generateBinaryTree(depth-1);
  return root;
}

void display(TreeNode* root){
  if(root!=NULL){
    display(root->left);
    cout << root->val << ",";
    display(root->right);
  }
  return;
}


int checkHeight(TreeNode* root){
  if (root==NULL) return -1;
  
  int leftHeight = checkHeight(root->left);
  if (leftHeight==INT32_MIN) return INT32_MIN;

  int rightHeight = checkHeight(root->right);
  if (rightHeight==INT32_MIN) return INT32_MIN;

  int heightDiff = abs(rightHeight-leftHeight);
  
  if (heightDiff>1) {
    return INT32_MIN;
  } else {
    return (max(leftHeight, rightHeight) + 1 );
  }
}

bool checkBalanced(TreeNode* root){
  return (checkHeight(root) != INT32_MIN);
}


int main(){
  int depth = 5;
  TreeNode* root = generateBinaryTree(depth);
  display(root);
  cout << endl;
  cout << (checkBalanced(root)? "Balanced" : "Not balanced") << endl;
  return 0;
}