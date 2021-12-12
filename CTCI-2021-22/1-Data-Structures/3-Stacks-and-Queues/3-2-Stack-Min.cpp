#include <iostream>

using namespace std;

class stack{
  private:
  int stack_size;
  int curr_index;
  int *arr;
  public:
  stack(int size){
    stack_size = size;
    arr = (int*)malloc(sizeof(int)*size);
    curr_index = -1;
  }
  bool push(int data){
    if (curr_index >= stack_size-1){
      cout << "Stack overflow" << endl;
      return false;
    }
    arr[++curr_index] = data;
    return true;
  }
  bool pop(){
    if (curr_index < 0){
      cout << "Stack underflow" << endl;
      return false;
    }
    arr[curr_index--] = 0;
    return true;
  }
  int peek(){
    if (curr_index < 0){
      cout << "Stack underflow" << endl;
      return false;
    }
    return arr[curr_index];
  }
  void display(){
    for(int i=0; i<=curr_index; i++){
      cout << arr[i] << ", ";
    }
    cout << endl;
  }
};


class minStack: public stack{
  int min = INT32_MAX;
  stack *minValues;
  public:
  minStack (int size) : stack(size) {
    minValues = new stack(size);  
  }
  bool push(int data){
    if(data <= min){
      min = data;
      minValues->push(data);
    }
    return stack::push(data);
  }
  bool pop(){
    int val = stack::peek();
    if(val == min){
      minValues->pop();
    }
    return stack::pop();
  }
  int get_min(){
    return minValues->peek();
  }
};

int main(){
  minStack stack(10);
  stack.push(5);
  stack.display();
  stack.push(3);
  stack.display();
  stack.push(2);
  stack.display();
  stack.push(1);
  stack.display();
  cout << stack.peek() << endl;
  cout << stack.get_min() << endl;
  stack.pop();
  stack.display();
  cout << stack.get_min() << endl;

  return 0;
}