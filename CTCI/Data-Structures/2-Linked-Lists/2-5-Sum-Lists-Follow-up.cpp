#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class nodeWithCarry{
    public:
    int carry;
    Node* node;
};

// finds length of a linked list
int findLength(Node* a){
    int n=0;
    while(a){
        a = a->next;
        n++;
    }
    return n;
}

void display(Node*head){
    int actualNumber=0;
    while(head){
        cout << head << " -> " << head->data << " | ";
        actualNumber*=10;
        actualNumber+=head->data;
        head = head->next;
    }
    cout << " Actual Number = " << actualNumber << endl;
    return;
}

// inserts data at head and returns new head
Node* insertAtHead(Node* head, int data){
    Node *temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
    // display(temp);
    return head;
}

// recursive call to perform add from the last element
nodeWithCarry* makeSum(Node*a, Node*b){
    nodeWithCarry *curr = new nodeWithCarry();
    nodeWithCarry *old = new nodeWithCarry();
    if(a->next && b->next){
        old = makeSum(a->next, b->next);
    }
    int sum = (a->data + b->data + old->carry)%10;
    curr->node = insertAtHead(old->node,sum);
    curr->carry = (a->data + b->data + old->carry)/10;
    return curr;
}

// O(n) solution by putting result in another linked list simlutaneously
Node* sumList (Node *aHead, Node *bHead){
    Node *result=NULL;
    // we neeed to add padding to smaller list to make their length same
    int lengthDifference = findLength(aHead) - findLength(bHead);
    // if a has more element than b
    if (lengthDifference > 0){
        while (lengthDifference!=0){
            bHead = insertAtHead(bHead,0);
            lengthDifference--;
        }
    }
    // if b has more element than a
    else if (lengthDifference < 0){
        while (lengthDifference!=0){
            aHead = insertAtHead(aHead,0);
            lengthDifference++;
        }
    }
    nodeWithCarry* temp = makeSum(aHead,bHead);
    // checking if we have any left over carry
    if (temp->carry) temp->node = insertAtHead(temp->node,temp->carry);
    return temp->node;
}

int main(){
    Node *aHead=NULL, *bHead=NULL, *resultHead=NULL, *temp;
    for (int i=6;i<9;i++){
        temp = new Node();
        temp->data = i;
        temp->next = aHead;
        aHead = temp;
    }
    for (int i=4;i<8;i++){
        temp = new Node();
        temp->data = i;
        temp->next = bHead;
        bHead = temp;
    }
    display(aHead);
    cout << "+" << endl;
    display(bHead);
    cout << "=" << endl;
    resultHead = sumList(aHead,bHead);
    display(resultHead);
    return 0;
}