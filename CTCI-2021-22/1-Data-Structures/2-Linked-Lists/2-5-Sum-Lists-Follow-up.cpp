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

Node* sumNum(Node* num_1, Node* num_2){
  Node* sum = NULL, *curr = NULL;
  int digit, carry = 0;
  while(num_1!=NULL || num_2!=NULL || carry>0){
    digit = 0;
    if (num_1!=NULL) {
      digit += num_1->data;
      num_1 = num_1->next;
    } 
    if (num_2!=NULL) {
      digit += num_2->data;
      num_2 = num_2->next;
    } 
    if (carry>0) {
      digit += carry;
      carry = 0;
    }
    carry = digit/10;
    digit = digit%10;
    Node* temp = new Node();
    temp->data = digit;
    temp->next = NULL;
    if (sum==NULL) sum = temp;
    if (curr==NULL) {
      curr = temp;
    } else {
      curr->next = temp;
      curr = curr->next; 
    }
  }
  return sum;
}

int main(){
  int length = 10;
  Node* num_1 = generateLinkedList(length);
  Node* num_2 = generateLinkedList(length);
  cout << "Original number 1: " << endl;
  display(num_1);
  cout << "Original number 2: " << endl;
  display(num_2);
  Node* sum = sumNum(num_1, num_2);
  cout << "Sum : " << endl;
  display(sum);
  return 0;
}