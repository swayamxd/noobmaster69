#include<iostream>
#include<stdlib.h>
#include<stack>
#include<vector>
using namespace std;

class autoExtendStack{
    int stackSize;
    public:
    // declare a vector of stacks
    vector<stack<int>> stackVector;
    // this stack will help in current push and pop
    stack<int> currentStack;
    autoExtendStack(int size){
        stackSize = size;
    }
    void push(int value){
        if(currentStack.size()==stackSize) {
            stackVector.push_back(currentStack);
            while(!currentStack.empty()){
                currentStack.pop();
            }
        }
        currentStack.push(value);
    }
    void pop(){
        while(currentStack.empty()){
            if (stackVector.empty()) return;
            currentStack = stackVector.back();
            stackVector.pop_back();
        }
        currentStack.pop();
        return;
    }
    int top(){
        while(currentStack.empty()){
            if (stackVector.empty()) return -1;
            currentStack = stackVector.back();
            stackVector.pop_back();
        }
        return currentStack.top();
    }
    void pop(int stackNum){
        if (stackNum<=stackVector.size()){
            if (stackVector[stackNum].empty()){
                (stackNum==0)?stackNum++:stackNum--;
            }
            cout << "Popping from stack "<< stackNum << " : " << stackVector[stackNum].top() << endl;
            stackVector[stackNum].pop();
        }
        else if(stackNum==stackVector.size()+1){
            if(currentStack.empty()){
                pop(--stackNum);
                return;
            }
            cout << "Popping from stack "<< stackNum << " : " << currentStack.top() << endl;
            currentStack.pop();
        }
        return;
    }
};

int main(){
    int stackSize = 3;
    int stackNum = 1;
    autoExtendStack exStack(stackSize);
    cout << "stack data :" << endl;
    for (int i=0;i<10;i++){
        int data = rand()%100;
        cout << data << " , ";
        exStack.push(data);
    }
    cout << endl;
    for (int i=0;i<4;i++){
        exStack.pop(stackNum);
    }
    for (int i=0;i<10;i++){
        cout << "Stack top after "<< i << "th pop : " << exStack.top() << endl;
        exStack.pop();
    }
    return 0;
}