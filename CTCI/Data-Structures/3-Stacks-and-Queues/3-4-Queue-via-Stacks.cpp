#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

class queueUsingStack{
    stack<int> first;
    stack<int> second;
    public:
    void push(int value){
        first.push(value);
    }
    void pop(){
        if(second.empty()){
            if(first.empty()) return;
            while(!first.empty()){
                second.push(first.top());
                first.pop();
            }
        }
        second.pop();
        return;
    }
    int top(){
        if(second.empty()){
            if(first.empty()) return -1;
            while(!first.empty()){
                second.push(first.top());
                first.pop();
            }
        }
        return second.top();
    }
};

int main(){
    queueUsingStack stack;
    cout << "stack input data :" << endl;
    for (int i=0;i<10;i++){
        int data = rand()%10;
        cout << data << " , ";
        stack.push(data);
    }
    cout << endl << "queue pop data : " << endl;
    for (int i=0;i<13;i++){
        cout << stack.top() << " , ";
        stack.pop();
    }
    cout << endl ;
    return 0;
}