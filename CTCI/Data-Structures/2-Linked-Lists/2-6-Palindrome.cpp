#include<iostream>
#include<stack>
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

int findLength(Node*a){
    int n=0;
    while(a){
        a=a->next;
        n++;
    }
    return n;
}

// to reverse a linked list
Node* reverse(Node*head){
    Node* a, *temp;
    stack<int> reverseList;
    while(head){
        temp= new Node();
        temp->data = head->data;
        temp->next = a;
        a = temp;
        head = head->next;
    }
    return a;
}

// O(n) solution using reversal
bool checkPalindrome(Node *head){
    Node *a = reverse(head);
    while(head){
        if(head->data != a->data){
            return false;
        }
        head = head->next;
        a = a->next;
    }
    return true;
}

/*
// O(n) solution using two pointers with stack
bool checkPalindrome(Node *a){
    stack<int> firstHalfValue;
    Node *curr=a, *fast=a;
    while (fast && fast->next){
        firstHalfValue.push(curr->data);
        curr=curr->next;
        fast=fast->next->next;
    }
    // if length is odd, then skipping middle element by checking with stack
    if (firstHalfValue.top() != curr->data) curr = curr->next;
    while (curr){
        if(firstHalfValue.top() != curr->data){
            return false;
        }
        firstHalfValue.pop();
        curr = curr->next;
    }
    return true;
}

// O(n+(n/2)) solution using stack
bool checkPalindrome(Node *a){
    stack<int> firstHalfValue;
    Node *curr=a;
    for (int i=0;i<findLength(a)/2;i++){
        firstHalfValue.push(curr->data);
        curr=curr->next;
    }
    // if length is odd, then skipping middle element
    if (findLength(a)&1) curr = curr->next;
    while (curr){
        if(firstHalfValue.top() != curr->data){
            return false;
        }
        firstHalfValue.pop();
        curr = curr->next;
    }
    return true;
}
*/

int main(){
    Node *head=NULL,*temp;
    for(int i=1;i<5;i++){
        temp = new Node();
        temp->data = i;
        temp->next = head;
        head = temp;
    }
    for(int i=5;i>0;i--){
        temp = new Node();
        temp->data = i;
        temp->next = head;
        head = temp;
    }
    cout << "Input Linked List :" << endl;
    display(head);
    (checkPalindrome(head)) ? cout << "Palindrome" << endl : cout << "Not Palindrome" << endl;
    return 0;
}