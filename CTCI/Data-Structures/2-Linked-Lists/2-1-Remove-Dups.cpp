#include<iostream>
#include<stdlib.h>
#include<unordered_set>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void display(Node* head){
    while(head->next!=NULL){
        cout << head << " -> " << head->data << " | ";
        head = head->next;
    }
    cout << endl;
    return;
}

/*
// O(n^2) solution with using no buffer
void removeDuplicates(Node* head){
    Node *curr=head, *after=NULL, *dup=NULL;
    while (curr!=NULL){
        after = curr->next;
        while (after!=NULL){
            if (curr->data == after->data){
                dup = after;
                curr->next = after->next;
                after = after->next;
                delete(dup);
            } else {
                after = after->next;
            }
        }
        curr = curr->next;
    }
    return;
}
*/

// O(n) solution using unordered_set
void removeDuplicates(Node* head){
    Node *curr=head, *prev=NULL, *dup;
    unordered_set<int> duplicateTable;
    while (curr!=NULL){
        if (duplicateTable.find(curr->data)!=duplicateTable.end()) {
            dup = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete(dup);
        } else {
            duplicateTable.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
    return;
}

int main(){
    Node* head = new Node();
    Node* temp = head;
    for (int i=10;i<20;i++){
        temp->data = i/3;
        temp->next = new Node();
        temp = temp->next;
    }
    cout << "Input Linked List:" << endl;
    display(head);
    removeDuplicates(head);
    cout << "After removing duplicates:" << endl;
    display(head);
    return 0;
}