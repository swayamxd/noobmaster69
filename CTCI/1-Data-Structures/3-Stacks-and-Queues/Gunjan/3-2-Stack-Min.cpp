#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

class minStack{
    private:
    stack<int> superStack;
    stack<int> minStack;
    public:
    void push(int value){
        if(minStack.empty() || minStack.top() > value){
            minStack.push(value);
        }
        superStack.push(value);
    }
    void pop(){
        if(!minStack.empty() && minStack.top() == superStack.top()){
            minStack.pop();
        }
        superStack.pop();
        return;
    }
    int top(){
        if (!superStack.empty()) return superStack.top();
        return 0;
    }
    int min(){
        if (!minStack.empty()) return minStack.top();
        return 0;
    }
};

int main(){
    minStack stack;
    cout << "stack data :" << endl;
    for (int i=0;i<10;i++){
        int data = rand()%10;
        // int data = 10-i;
        cout << data << " , ";
        stack.push(data);
    }
    cout << endl << "Tallying with min with stack :\nstack : min" << endl;
    for (int i=0;i<10;i++){
        cout << stack.top() << " : " << stack.min() << endl;
        stack.pop();
    }
    return 0;
}