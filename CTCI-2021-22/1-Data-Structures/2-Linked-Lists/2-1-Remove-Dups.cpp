#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <unordered_set>

using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* generateLinkedList(int length){
  srand(time(0));
  Node* head = NULL;
  for (int i=0 ; i<length; i++){
    Node* temp = new Node();
    temp->data = rand()%5;
    temp->next = head;
    head = temp;
  }
  return head;
}

void display(Node* head){
  while(head){
    cout << head->data << " -> ";
    head = head->next;
  }
  cout << endl;
}


// using two pointerrs
// time complexity O(n^2)
// space complexity O(1)
void removeDups(Node* head){
  Node *i=head, *j, *dup;
  while(i){
    j = i;
    while(j && j->next){
      if (i->data == j->next->data){
        dup = j->next;
        j->next = j->next->next;
        delete(dup);
      } else {
        j = j->next;
      }
    }
    i = i->next;
  }
}

/*
// using unordered map
// time complexity O(n)
// space complexity O(n)
void removeDups(Node* head){
  unordered_set<int> dup_table;
  Node *curr=head, *prev=NULL, *dup;
  while(curr){
    if (dup_table.find(curr->data)!=dup_table.end()){
      dup = curr;
      curr = curr->next;
      prev->next = curr;
      delete(dup);
    } else {
      dup_table.insert(curr->data);
      prev = curr;
      curr = curr->next;
    }
  }
}*/

int main(){
  int linked_list_length = 10;
  Node* head = generateLinkedList(linked_list_length);
  cout << "Original linked list : " << endl;
  display(head);
  removeDups(head);
  cout << "Unique linked list : " << endl;
  display(head);
  return 0;
}