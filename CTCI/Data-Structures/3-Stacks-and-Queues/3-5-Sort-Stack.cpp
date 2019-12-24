#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

// O(n^2) solution using auxiliary stack
// logic is tough to figure out on own, refer to CTCT pageNum: 237
void sortStack(stack<int> &inputStack){
    stack<int> auxilaryStack;
    int currentElement;
    while(!inputStack.empty()){
        currentElement = inputStack.top();
        inputStack.pop();
        if (auxilaryStack.empty()) {
            auxilaryStack.push(currentElement);
            continue;
        }
        while(auxilaryStack.top() > currentElement){
            inputStack.push(auxilaryStack.top());
            auxilaryStack.pop();
            if (auxilaryStack.empty()) {
                break;
            }
        }
        auxilaryStack.push(currentElement);
    }
    while(!auxilaryStack.empty()){
        inputStack.push(auxilaryStack.top());
        auxilaryStack.pop();
    }
}

int main(){
    stack<int> inputStack;
    cout << "stack input data :" << endl;
    for (int i=0;i<10;i++){
        int data = rand()%10;
        // int data = 10-i;
        cout << data << " , ";
        inputStack.push(data);
    }
    cout << endl << "sorted stack pop data : " << endl;
    sortStack(inputStack);
    for (int i=0;i<10;i++){
        cout << inputStack.top() << " , ";
        inputStack.pop();
    }
    cout << endl ;
    return 0;
}