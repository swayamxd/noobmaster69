#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int findLength(Node* a){
    int n=0;
    while(a){
        a = a->next;
        n++;
    }
    return n;
}

void display(Node*head){
    int actualNumber=0;
    while(head){
        cout << head << " -> " << head->data << " | ";
        actualNumber*=10;
        actualNumber+=head->data;
        head = head->next;
    }
    cout << " Actual Number = " << actualNumber << endl;
    return;
}

// inserts data at head and returns new head
Node* insertAtHead(Node* head, int data){
    Node *temp = new Node();
    temp->data = data;
    if (head) {
        temp->next = head;
    } else {
        temp->next = NULL;
    }
    head = temp;
    return head;
}

// O(n) solution by putting result in another linked list simlutaneously
Node* sumList (Node *aHead, Node *bHead){
    int carry=0, lengthDifference;
    // if difference is negative, then b is larger else vice versa
    lengthDifference = findLength(aHead)-findLength(bHead);
    Node *temp, *result=NULL, *prev=NULL;
    Node *a = aHead;
    Node *b = bHead;

    // while actually adding a and b
    while(a && b){
        temp = new Node();
        // if result is empty, replace result with temp
        if(!result) {
            result = temp;
            prev = temp;
        }
        temp->data = (carry + a->data + b->data)%10;
        carry = (a->data + b->data)/10;
        temp->next = NULL;
        if (result) {
            prev->next = temp;
            prev = prev->next;
        }
        a = a->next;
        b = b->next;
    }
    // copying remaining a with carry
    while (a){
        temp = new Node();
        temp->data = a->data + carry;
        carry = 0;
        temp->next = NULL;
        prev->next = temp;
        prev = prev->next;
        a = a->next;
    }
    // copying remaining b with carry
    while (b){
        temp = new Node();
        temp->data = b->data + carry;
        carry = 0;
        temp->next = NULL;
        prev->next = temp;
        prev = prev->next;
        b = b->next;
    }
    // copying remaining carry
    if (carry){
        temp = new Node();
        temp->data = carry;
        temp->next = NULL;
        prev->next = temp;
    }
    return result;
}

int main(){
    Node *aHead=NULL, *bHead=NULL, *resultHead=NULL, *temp;
    for (int i=6;i<9;i++){
        temp = new Node();
        temp->data = i;
        temp->next = aHead;
        aHead = temp;
    }
    for (int i=4;i<9;i++){
        temp = new Node();
        temp->data = i;
        temp->next = bHead;
        bHead = temp;
    }
    display(aHead);
    cout << "+" << endl;
    display(bHead);
    cout << "=" << endl;
    resultHead = sumList(aHead,bHead);
    display(resultHead);
    return 0;
}