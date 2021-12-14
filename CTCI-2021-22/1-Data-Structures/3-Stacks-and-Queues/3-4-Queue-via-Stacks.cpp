#include<iostream>
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
    return (_index+1);
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

class MyQueue{
  private:
  stack *stack_out, *stack_in;
  void shift(){
    if (stack_out->size()==0){
      while(stack_in->size()){
        stack_out->push(stack_in->peek());
        stack_in->pop();
      }
    }
  }
  public:
  MyQueue(int size){
    stack_in = new stack(size);
    stack_out = new stack(size);
  }
  bool enqueue(int data){
    return stack_in->push(data);
  }
  bool dequeue(){
    shift();
    return stack_out->pop();
  }
  int peek(){
    shift();
    return stack_out->peek();
  }
  void display(){
    cout << "============" << endl;
    cout << "Stack In" << endl;
    stack_in->display();
    cout << "Stack Out" << endl;
    stack_out->display();
    cout << "============" << endl;
  }
};

int main(){
  MyQueue myqueue(20);

  for (int i=0; i<10; i++){
    myqueue.enqueue(i*5);
  }

  myqueue.display();
  cout << myqueue.peek() << endl;
  for (int i=0; i<5; i++){
    myqueue.dequeue();
  }
  myqueue.display();
  cout << myqueue.peek() << endl;

  return 0;
}