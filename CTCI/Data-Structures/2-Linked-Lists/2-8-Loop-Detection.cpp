#include<iostream>
#include<set>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void display(Node *head, int n){
    while(n){
        cout << head << " -> " << head->data << " | ";
        head = head->next;
        n--;
    }
    cout << endl;
    return;
}

// O(n) solution using Floyd's loop
Node *detectLoop(Node *head){
    bool loopFlag=true;
    Node *firstPointer=NULL;
    Node *secondPointer=NULL;
    Node *slowRunner=head;
    Node *fastRunner=head->next;
    while(slowRunner && fastRunner && fastRunner->next){
        if(slowRunner==fastRunner){
            loopFlag=false;
            break;
        }
        slowRunner = slowRunner->next;
        fastRunner = fastRunner->next->next;
    }
    // if loopFlag is false, then linked list has no loop
    if (loopFlag) return firstPointer;
    // determine the loop size
    int loopSize = 0;
    Node *temp=slowRunner;
    while(temp){
        temp=temp->next;
        loopSize++;
        if(temp==slowRunner) break;
    }
    // we will take first pointer to head, second pointer
    // to a node with distance of loopSize from head node,
    // if they collide, they will collide at loop position

    firstPointer = secondPointer = head;
    // setting second pointer to a distance of loopSize
    for (int i=0;i<loopSize;i++){
        secondPointer = secondPointer->next;
    }
    // now increment both pointers with single step to find out loop poisition
    while(true){
        if(firstPointer==secondPointer) break;
        firstPointer = firstPointer->next;
        secondPointer = secondPointer->next;
    }
    return firstPointer;
}

/*
// O(n) solution using set
Node *detectLoop(Node *head){
    Node *position=NULL;
    set<Node*> nodeSet;
    while(head){
        if(nodeSet.find(head)!=nodeSet.end()){
            position=head;
            break;
        }
        nodeSet.insert(head);
        head=head->next;
    }
    return position;
}
*/

int main(){
    int size=7;  //linkedList size
    int loopPosition=3;  //loopPosititon at
    Node* head=NULL, *loopNode=NULL, *temp;
    for(int i=0;i<size;i++){
        temp = new Node();
        temp->data = i;
        temp->next = head;
        head = temp;
    }
    // now make the linked list loop over loop node
    temp = head;
    for(int i=0;i<size;i++){
        if (i==loopPosition) loopNode = temp;
        if (i==size-1) temp->next = loopNode;
        temp = temp->next;
    }
    size++;
    display(head,size);
    Node* position = detectLoop(head);
    if (position){
        cout << "Loop position at : " << position << " -> " << position->data << endl;
    } else {
        cout << "No loop found" << endl;
    }
    return 0;
}