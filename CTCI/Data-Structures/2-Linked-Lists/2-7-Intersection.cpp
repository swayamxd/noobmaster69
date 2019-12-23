#include<iostream>
#include<set>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void display(Node* head){
    while (head){
        cout << head << " -> " << head->data << " | ";
        head = head->next;
    }
    cout << endl;
    return;
}

int findLength(Node *a){
    int n=0;
    while(a){
        a=a->next;
        n++;
    }
    return n;
}

/*
// O(a+b) solution using set
Node * findIntersection(Node *a, Node *b){
    set <int> aSet;
    Node *intersection = NULL;
    while(a){
        aSet.insert(a->data);
        a=a->next;
    }
    while(b){
        if(aSet.find(b->data)!=aSet.end()){
            intersection = b;
            break;
        }
        b = b->next;
    }
    return intersection;
}
*/

// O(a+b) solution without using set
Node *findIntersection(Node *a, Node *b){
    Node *intersection = NULL;
    int lengthDifference = findLength(a) - findLength(b);
    // means a is longer than b
    while (lengthDifference > 0){
        a = a->next;
        lengthDifference--;
    }
    // means b is longer than a
    while (lengthDifference < 0){
        b = b->next;
        lengthDifference++;
    }
    while(a && b){
        if(a==b){
            intersection = a;
            break;
        }
        a = a->next;
        b = b->next;
    }
    return intersection;
}

int main(){
    Node *aHead=NULL, *bHead=NULL;
    for(int i=10;i<16;i++){
        Node* temp = new Node();
        temp->data = i;
        temp->next = aHead;
        // intersection point, comment below line out to get unintersected linked lists
        if (i==13) bHead = temp;
        aHead = temp;
    }
    for(int i=1;i<4;i++){
        Node* temp = new Node();
        temp->data = i;
        temp->next = bHead;
        bHead = temp;
    }
    cout << "Input Linked List A: " <<  endl;
    display(aHead);
    cout << "Input Linked List B: " <<  endl;
    display(bHead);
    Node * intersection = findIntersection(aHead, bHead);
    if(intersection){
        cout << "Intersection at : " << intersection << endl;
        cout << "Common nodes : " << endl;
        display(intersection);
    } else {
        cout << "No intersection found" << endl;
    }
    return 0;
}