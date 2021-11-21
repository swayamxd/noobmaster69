#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void display(Node* head){
    while(head){
        cout << head << " -> " << head->data << " | ";
        head = head->next;
    }
    cout << endl;
    return;
}

Node* partition(Node* head, int n){
    Node* curr=head, *temp;
    while(curr->next){
        if(curr->next->data < n){
            temp = curr->next;
            curr->next = curr->next->next;
            temp->next = head;
            head = temp;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

int main(){
    // the value will decide which elements are on left, which are on right
    int partition_value = 4;
    Node* head=NULL, *temp;
    for (int i=0;i<7;i++){
        temp = new Node();
        temp->data = i;
        temp->next = head;
        head = temp;
    }
    cout << "Input Linked List :" << endl;
    display(head);
    head = partition(head,partition_value);
    cout << "Partitioned Linked List with partition value " << partition_value << ":" << endl;
    display(head);
    return 0;
}