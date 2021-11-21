#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Node{
  int data;
  struct Node* next;
};

Node* generateLinkedList(int length){
  srand(time(0));
  Node* head=NULL;
  for(int i=0; i<length; i++){
    Node* temp = new Node();
    temp->data = rand()%100;
    temp->next = head;
    head = temp; 
  }
  return head;
}

void display(Node* head){
  while(head!=NULL){
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << endl;
  return;
}

Node* retLastK(Node* head, int k){
  Node *curr = head, *prev = head;
  while(k-- && curr!=NULL){
    curr = curr->next;
  }
  while(curr!=NULL){
    curr = curr->next;
    prev = prev->next;
  }
  return prev;
}


int main(){
  int length = 10;
  Node* head = generateLinkedList(length);
  cout << "Generated linked list : " << endl;
  display(head);
  int k = 5;
  cout << k << " th element to last : " << retLastK(head, k)->data << endl;
  return 0;
}