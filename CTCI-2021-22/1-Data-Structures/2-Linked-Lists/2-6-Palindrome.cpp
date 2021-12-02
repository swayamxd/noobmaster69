#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Node{
  int data;
  struct Node* next;
};

Node* generateLinkedList(int length){
  Node* head=NULL;
  srand(time(0));
  for(int i=0; i< length/2;i++){
    Node* temp = new Node();
    temp->data = (length/2) - i-1;
    temp->next = head;
    head = temp;
  }
  for(int i=0; i< length/2;i++){
    Node* temp = new Node();
    temp->data = i;
    temp->next = head;
    head = temp;
  }
  return head;
}

void display(Node* head){
  while(head!=NULL){
    // cout <<"[" << head << " | " << head->data <<"] -> ";
    cout << head->data <<" -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
  return;
}

Node* reverse(Node* head){
  Node* new_head = NULL;
  while(head!=NULL){
    Node* temp = new Node();
    temp->data = head->data;
    temp->next = new_head;
    new_head = temp;
    head = head->next;
  }
  return new_head;
}

bool isPalindrome(Node* head){
  Node* reversed_ll = reverse(head);
  while(head!=NULL && reversed_ll!=NULL){
    if(head->data != reversed_ll->data) return false;
    head = head->next;
    reversed_ll = reversed_ll->next;
  }
  return true;
}

int main(){
  int length = 10;
  Node* head = generateLinkedList(length);
  cout << "Original linked list : " << endl;
  display(head);
  cout << (isPalindrome(head)?"Palindrome":"Not palindrome") << endl;
  return 0;
}