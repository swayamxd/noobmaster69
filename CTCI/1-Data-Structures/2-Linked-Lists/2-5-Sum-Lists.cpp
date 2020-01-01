#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void display(Node*head){
    int actualNumber=0, i=1;
    while(head){
        cout << head << " -> " << head->data << " | ";
        actualNumber+=i*head->data;
        i*=10;
        head = head->next;
    }
    cout << " Actual Number = " << actualNumber << endl;
    return;
}

// O(n) solution by putting result in another linked list simlutaneously
Node* sumList (Node *a,Node *b){
    int carry=0;
    Node *temp, *result=NULL, *prev=NULL;
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