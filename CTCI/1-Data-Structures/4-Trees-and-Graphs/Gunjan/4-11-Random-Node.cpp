#include<iostream>
using namespace std;

class BST{
    int data;
    int size=0;
    BST* left;
    BST* right;
    int deleteNode(BST* node){
        int data = node->data;
        if (node->left==NULL && node->right==NULL){
            // BST* toDelete = node;
            cout << node->data << endl;
            // delete(node);
            node = node->left;
            // delete(toDelete);
        } else if(node->left==NULL){
            BST* toDelete = node->right;
            node = node->right;
            delete(toDelete);
        } else if(node->right==NULL){
            BST* toDelete = node->left;
            node = node->left;
            delete(toDelete);
        }
        return data;
    }
    BST* inOrderSuccessor(int d){
        bool flag = false;
        BST* root = this;
        BST* current = root;
        // find root which has same data as d
        while(current && !flag){
            if(current->data==d) flag=true;
            (current->data < d) ? current = current->right : current = current->left;
        }
        // if not found return NULL
        if (!flag) return NULL;
        // if found, check if right child exists
        if(current->right) {
            // if right child exists, then in order successor will be
            current = current->right;
            // the left most element of the right subtree
            while(current->left) current = current->left;
        }
        // if not found
        else {
            while(root){
                // if root data greater than target data, go left,
                // if going left, then there is right node definitely
                // then inorder successor can be right node
                if(d < root->data){
                    current = root;
                    root = root->left;
                }
                // if root data less than target data, go right,
                // if going right, then there is no new inorder successor
                else if(d > root->data) {
                    root = root->right;
                }
                // if root data equals to target data, break as we already
                // have previous inorder successor
                else break;
            }
        }
        return current;
    }
    public:
    BST(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    void display(){
        if(this->left) this->left->display();
        cout << this->data << " ; ";
        if(this->right) this->right->display();
    }
    int getSize() {return size;}
    int getData() {return data;}
    void insert(int d){
        if(d<=data) {
            if(left==NULL) left = new BST(d);
            else left->insert(d);
        } else {
            if(right==NULL) right = new BST(d);
            else right->insert(d);
        }
        this->size++;
    }
    BST* find(int d){
        if(!this) return this;
        if (d==data) return this;
        else if(d<data) (left) ? left->find(d) : NULL;
        else (right) ? right->find(d) : NULL;
        return NULL;
    }
    void remove(int d){
        this->display(); cout << " | " <<this->data << endl;
        if(!this) return;
        else if(d==data) {
            if (this->left == NULL || this->right == NULL) deleteNode(this);
            else this->data = deleteNode(inOrderSuccessor(d));
        } else if(d<data) {
            if(left==NULL) return;
            else left->remove(d);
        } else {
            if(right==NULL) return;
            else right->remove(d);
        }
        this->size--;
    }
};

int main(){
    BST* tree = new BST(7);
    tree->insert(5);
    tree->insert(4);
    tree->insert(6);
    tree->display(); cout << endl;
    tree->remove(7);
    (tree->find(2)) ? cout << "Found" << endl : cout << "Not found" << endl;
    tree->display(); cout << endl;
    return 0;
}