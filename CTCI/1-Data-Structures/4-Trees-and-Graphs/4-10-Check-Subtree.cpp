#include<iostream>
#include<string>
using namespace std;

class binaryTree{
    public:
    int data;
    binaryTree* left;
    binaryTree* right;
};

void displayTree(binaryTree*root){
    if(!root) return;
    cout << root->data << " ; ";
    displayTree(root->left);
    displayTree(root->right);
}

binaryTree * generateBinaryTree(int depth){
    if(!depth) return NULL;
    binaryTree *currentNode = new binaryTree();
    currentNode->data = depth;
    currentNode->left = generateBinaryTree(depth-1);
    currentNode->right = generateBinaryTree(depth-1);
    return currentNode;
}

/*
// preorder traversal, and return X where NULL, to get unique representation of a tree
string getString(binaryTree* root){
    // string treeRepresentation;
    if(!root) return "X";
    return to_string(root->data) + getString(root->left) + getString(root->right);
}

// timeComplexity: O(m+n) , spaceComplexity: O(m+n)
bool checkSubtree(binaryTree* first, binaryTree* second){
    string firstString = getString(first);
    string secondString = getString(second);
    if (firstString.find(secondString) != firstString.npos) return true;
    return false;
}
*/

bool checkSubTreeHelper(binaryTree* first, binaryTree* second){
    // if first and second both are NULL, it's matching
    if(!first && !second) return true;
    // if first or second is NULL, it's not matching
    else if(!first || !second) return false;
    else if(first->data != second->data) return false;
    else return checkSubTreeHelper(first->left, second->left) && checkSubTreeHelper(first->right, second->right);
    return false;
}

// timeComplexity: O(m*n) , spaceComplexity: O(log(m) + log(n))
bool checkSubtree(binaryTree* first, binaryTree* second){
    // if second is NULL, it's already contained in the first tree
    if(!second) return true;

    // if first is NULL, second tree can't be contained inside first
    else if(!first) return false;

    // if data doesn't match, go to left and right
    else if(first->data==second->data && checkSubTreeHelper(first,second)){
        return true;
    }
    return checkSubtree(first->left,second) || checkSubtree(first->right,second);
}

int main(){
    int depth = 5;
    binaryTree* first = generateBinaryTree(depth);
    binaryTree* second = generateBinaryTree(depth-1);
    displayTree(first);
    cout << endl;
    displayTree(second);
    cout << endl;
    checkSubtree(first,second) ? cout << "subTree Found" << endl : cout << "Subtree not found" << endl ;
    return 0;
}