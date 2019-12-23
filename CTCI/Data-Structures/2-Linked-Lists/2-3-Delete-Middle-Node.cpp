#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void display(Node* head){
    while(head){
        cout << head << "->" << head->data << " | ";
        head = head->next;
    }
    cout << endl;
    return;
}

// O(1) solution by swapping current with next element
void deleteMiddle(Node *midNode){
    Node* toDelete = midNode->next;
    midNode->data = midNode->next->data;
    midNode->next = midNode->next->next;
    delete(toDelete);
    return;
}

int main(){
    // the node index to delete
    int n=2;
    Node* head=NULL, *temp, *midNode;
    for (int i=0;i<6;i++){
        temp = new Node();
        temp->data = i;
        temp->next = head;
        head = temp;
    }
    midNode=head;
    for (int i=0;i<n;i++){
        // we want to delete this node
        midNode = midNode->next;
    }
    cout << "Input linked list :" << endl;
    display(head);
    cout << "linked list after deleting " << midNode->data <<  ":" << endl;
    deleteMiddle(midNode);
    display(head);
    return 0;
}