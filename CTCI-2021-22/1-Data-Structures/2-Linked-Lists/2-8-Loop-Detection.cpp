#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Node{
  int data;
  struct Node* next;
};

Node *generateCircularLL(int length){
  srand(time(0));
  Node *head=NULL, *tail=NULL;
  for (int i=0; i<length; i++){
    Node *temp = new Node();
    temp->data = rand()%50;
    temp->next = head;
    if(head==NULL) {
      tail = temp;
    }
    if(i == length/3) {
      tail->next = temp;
    }
    head = temp;
  }
  return head;
}

void display(Node *head, int length){
  for (int i=0; i<length*3/2 && head!=NULL ; i++){
    cout << head->data << " --> ";
    head = head->next;
  }
  cout << endl;
}

// https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
Node *getLoopBeg(Node* head){
  Node *fast=head, *slow=head;
  while (true){
    if (fast==NULL || fast->next==NULL) return NULL;
    slow = slow->next;
    fast = fast->next->next;
    if (fast==slow) break;
  }
  slow = head;
  while(fast!=slow){
    fast = fast->next;
    slow = slow->next;
  }
  return fast;
}

int main(){
  int length = 10;
  Node *head = generateCircularLL(length);
  display(head, length);

  Node* loopBegin = getLoopBeg(head);
  cout << loopBegin->data << " --> " << endl;
  return 0;
}