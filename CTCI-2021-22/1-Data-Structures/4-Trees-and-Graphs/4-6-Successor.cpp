#include <iostream>

using namespace std;

class TreeNode{
  public:
  int val;
  TreeNode* parent;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* generateBinaryTree(TreeNode* root, int depth){
  if (!depth) return NULL;
  TreeNode* current = new TreeNode();
  current->val = depth*(depth+2);
  current->parent = root;
  current->left = generateBinaryTree(current, depth-1);
  current->right = generateBinaryTree(current, depth-1);
  return current;
}

void display(TreeNode* root){
  if (root==NULL) return;
  display(root->left);
  cout << root->val << ",";
  display(root->right);
  return;
}


TreeNode* inorderSuccessor(TreeNode* node){
  if(node==NULL) return NULL;
  if (node->right){
    node = node->right;
    while(node->left){
      node = node->left;
    }
    return node;
  } else {
    TreeNode* child = node;
    TreeNode* parent = node->parent;
    while(parent && parent->right!=child){
      child = child->parent;
      parent = parent->parent;
    }
    return parent;
  }
  return NULL;
}

int main(){
  int depth = 5;
  TreeNode* root = generateBinaryTree(NULL, depth);
  display(root);
  cout << endl;
  TreeNode* succ = inorderSuccessor(root->left->right);
  cout << root->left->right->val << endl;
  cout << succ->val << endl;
  return 0;
}