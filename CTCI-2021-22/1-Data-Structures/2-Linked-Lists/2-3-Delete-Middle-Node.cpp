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
    cout <<"[" << head << " | " << head->data <<"] -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
  return;
}

Node* getRandomNode(Node* head, int length){
  srand(time(0));
  int random_node_index = rand()%length;
  while(random_node_index--){
    head = head->next;
  }
  return head;
}

void deleteMiddleNode(Node* middle){
  if (middle && middle->next){
    Node* dup = middle->next;
    middle->data = middle->next->data;
    middle->next = middle->next->next;
    delete(dup);
    return;
  }
}

int main(){
  int length = 10;
  Node* head = generateLinkedList(length);
  cout << "Original linked list : " << endl;
  display(head);
  Node* randomNode = getRandomNode(head,length);
  cout << "Random node : " << randomNode << endl;
  deleteMiddleNode(randomNode);
  cout << "Polished linked list : " << endl;
  display(head);
  return 0;
}