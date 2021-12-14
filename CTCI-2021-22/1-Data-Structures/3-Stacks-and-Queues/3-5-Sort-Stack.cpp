#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class stack{
  private:
  int _size;
  int _index;
  int *_arr;
  
  public:
  stack(int size){
    _size = size;
    _index = -1;
    _arr = (int*)malloc(sizeof(int)*_size);
  }
  int size(){
    return _size;
  }
  bool isEmpty(){
    return (_index<0);
  }
  bool push(int data){
    if (_index>=_size-1){
      return false;
    }
    _arr[++_index] = data;
    return true;
  }
  bool pop(){
    if (_index<0){
      return false;
    }
    _arr[_index--] = 0;
    return true;
  }
  int peek(){
    if (_index<0){
      return INT32_MIN;
    }
    return _arr[_index];
  }
  void display(){
    for (int i=0; i<=_index; i++){
      cout << _arr[i] << ", ";
    }
    cout << endl;
  }
};


void sortStack(stack &s){
  stack temp(s.size());
  while(!s.isEmpty()){
    int top = s.peek();
    s.pop();
    while(!temp.isEmpty() && temp.peek()>top){
      s.push(temp.peek());
      temp.pop();
    }
    temp.push(top);
  }
  while(!temp.isEmpty()){
    s.push(temp.peek());
    temp.pop();
  }
}

int main(){
  srand(time(0));
  int size = 10;
  stack s(size);
  for (int i=0; i<size; i++){
    s.push(rand()%111);
  }
  cout << "Original Stack" << endl;
  s.display();
  sortStack(s);
  cout << "Sorted Stack" << endl;
  s.display();
  return 0;
}