#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void display(Node* head){
    while(head!=NULL){
        cout << head << " -> " << head->data << " | ";
        head = head->next;
    }
    cout << endl;
    return;
}

// O(n) solution using 2 pointer iteration
int KthtoLast(Node* head, int k){
    Node *first=head,*second=head;
    while(k--){
        first = first->next;
    }
    while(first!=NULL){
        first=first->next;
        second=second->next;
    }
    return second->data;
}

int main(){
    int k=3;
    Node *head = NULL, *temp = NULL;
    for(int i=10;i<20;i++){
        temp = new Node();
        temp->data = i/3;
        temp->next = head;
        head = temp;
    }
    cout << "Input linked list: " << endl;
    display(head);
    cout << k << "th element from last of the linked list : " << KthtoLast(head,k)<< endl;
    return 0;
}