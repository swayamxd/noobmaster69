#include<iostream>
#include<stack>
using namespace std;

// prints a tower
void display(stack<int> tower){
    while(!tower.empty()){
        cout << tower.top() << ";";
        tower.pop();
    }
    cout << endl;
}

// generates a tower
stack<int> generateTower(int diskCount){
    stack<int> tower;
    while(diskCount--){
        tower.push(diskCount);
    }
    return tower;
}

// O(2^n) solution using recursion
void towerOfHanoi(int n, stack<int> &source,stack<int> &buffer,stack<int> &destination){
    // if there is no disk in source, return
    if(n==0) return;
    // move (n-1) disks to buffer so that there is only one disk left on source
    // making buffer as destination, and destination as buffer
    towerOfHanoi(n-1,source,destination,buffer);
    // move last nth disk from source to destination
    destination.push(source.top());
    source.pop();
    // now source is empty as buffer was at first
    // buffer contains all disk as source contained at first
    // so call the function again interchanging source and buffer
    towerOfHanoi(n-1,buffer,source,destination);
}

// create auxiliary and destination towers
stack<int> towerOfHanoi(stack<int> source){
    stack<int> buffer;
    stack<int> destination;
    towerOfHanoi(source.size(),source,buffer,destination);
    return destination;
}

int main(){
    int diskCount = 10;
    display(towerOfHanoi(generateTower(diskCount)));
    return 0;
}