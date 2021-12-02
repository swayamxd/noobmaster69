#include <iostream>

using namespace std;

struct Node{
  int data;
  struct Node *next;
};

void display(Node* head){
  while(head!=NULL){
    cout << "[ " << head << " | " << head->data << " ] --> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}

int findLength(Node *head){
  int i=0;
  while(head!=NULL){
    i++;
    head=head->next;
  }
  return i;
}

Node* findIntersection(Node *head1, Node *head2){
  int length1 = findLength(head1);
  int length2 = findLength(head2);
  if (length1>length2){
    for(int i=0; i< (length1-length2); i++) head1=head1->next;
  }
  else if (length2>length1){
    for(int i=0; i< (length2-length1); i++) head2=head2->next;
  }
  while(head1!=NULL){
    if (head1==head2) return head1;
    head1 = head1->next;
    head2 = head2->next;
  }

  return NULL;
}

int main(){
  Node *head1=NULL, *head2=NULL, *randIntersection=NULL;
  for (int i=0; i<30; i++){
    Node *temp = new Node();
    temp->data = i;
    temp->next = head1;
    head1 = temp;
    if ( i==15 ){
      randIntersection = temp;
    }
  }
  head2 = randIntersection;
  for (int i=0; i<40; i++){
    Node *temp = new Node();
    temp->data = i;
    temp->next = head2;
    head2 = temp;
  }
  display(head1);
  display(head2);
  Node *intersection = findIntersection(head1, head2); 
  cout << "[ " << randIntersection << " | " << randIntersection->data << " ]" << endl;
  cout << "[ " << intersection << " | " << intersection->data << " ]" << endl;
  return 0;
}