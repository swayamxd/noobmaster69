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
  while(length--){
    Node* temp = new Node();
    temp->data = rand()%10;
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

Node* partition(Node* head, int pivot){
  Node* new_head = NULL, *new_tail = NULL;
  while(head!=NULL){
    Node* temp = new Node();
    temp->data = head->data;
    // cout << temp->data << endl;
    if (head->data<pivot) {
      // insert at head
      temp->next = new_head;
      new_head = temp;
      if (new_tail==NULL) new_tail = new_head;
    }
    else {
      // insert at tail
      temp->next = NULL;
      if (new_tail!=NULL) new_tail->next = temp;
      new_tail = temp;
      if (new_head==NULL) new_head = new_tail;
    }
    head = head->next;
  }
  return new_head;
}

int main(){
  int length = 10;
  Node* head = generateLinkedList(length);
  cout << "Original linked list : " << endl;
  display(head);
  srand(time(0));
  int pivot = rand()%10;
  cout << "Pivot : " << pivot << endl;
  Node* newList = partition(head, pivot);
  cout << "Partitioned linked list : " << endl;
  display(newList);
  return 0;
}