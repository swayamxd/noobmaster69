#include <iostream>
#include <vector>
using namespace std;

class stack{
  private:
  int _size;
  int _index;
  int *_arr;
  public:
  stack(int size){
    _size = size;
    _arr = (int*)malloc(sizeof(int)*_size);
    _index = -1;
  }
  bool push(int data){
    if (_index>=_size-1){
      // cout << "Stack overflow" << endl;
      return false;
    }
    _arr[++_index] = data;
    return true;
  }
  bool pop(){
    if (_index<0){
      // cout << "Stack underflow" << endl;
      return false;
    }
    _arr[_index--] = 0;
    return true;
  }
  int peek(){
    if (_index<0){
      // cout << "Stack underflow" << endl;
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

class stackPlates{
  private:
  int _size;
  int _currIndex;
  int _stackIndex;
  vector<stack> _stack_plates;
  public:
  stackPlates(int size){
    _size = size;
    _stackIndex = 0;
    _stack_plates.push_back(stack(_size));
  }

  bool push(int data){
    if (!(_stack_plates[_stackIndex].push(data))){
      _stack_plates.push_back(stack(_size));
      _stack_plates[++_stackIndex].push(data);
    }
    return true;
  }

  bool pop(){
    if (!(_stack_plates[_stackIndex].pop())){
      _stack_plates.pop_back();
      _stack_plates[--_stackIndex].pop();
    }
    return true;
  }

  int peek(){
    if (_stack_plates[_stackIndex].peek() == INT32_MIN){
      _stack_plates.pop_back();
      return _stack_plates[--_stackIndex].peek();
    }
    return _stack_plates[_stackIndex].peek();
  }

  void display(){
    cout << "============" << endl;
    cout << "Stack Plates" << endl;
    for(int i=0; i<_stack_plates.size(); i++){
      cout << "Stack " << (i+1) << endl;
      _stack_plates[i].display();
    }
    cout << "============" << endl;
  }

};

int main(){
  stackPlates stack(3);

  for (int i=0; i<10; i++){
    stack.push(i*5);
  }

  stack.display();
  cout << stack.peek() << endl;
  for (int i=0; i<5; i++){
    stack.pop();
  }
  stack.display();
  cout << stack.peek() << endl;

  return 0;
}