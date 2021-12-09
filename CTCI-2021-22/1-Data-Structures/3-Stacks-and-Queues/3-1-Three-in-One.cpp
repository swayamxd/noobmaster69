#include<iostream>

using namespace std;

class threeStack{
  private:
  int *arr;
  int arraySize;
  int stackSize;
  int stackIndex[3] = {-1, -1, -1};

  public:
  threeStack(int size){
    arraySize=size;
    stackSize=arraySize/3;
    arr = (int *)malloc(sizeof(int)*arraySize);
  }

  void display(){
    for (int stackNum=0; stackNum<sizeof(stackIndex)/sizeof(stackIndex[0]); stackNum++){
      cout << stackNum << "th stack : ";
      for (int i=0; i<=stackIndex[stackNum]; i++){
        cout << arr[stackNum*stackSize + stackIndex[stackNum]] << ", ";
      }
      cout << endl;
    }
    cout << endl;
    return;
  }

  bool push(int data, int stackNum){
    if (stackIndex[stackNum] >= stackSize-1){
      cout << "Buffer overflow" << endl;
      return false;
    }
    stackIndex[stackNum]++;
    arr[stackNum*stackSize + stackIndex[stackNum]] = data;
    return true;
  }

  bool pop(int stackNum){
    if (stackIndex[stackNum] < 0){
      cout << "Buffer underflow" << endl;
      return false;
    }
    arr[stackNum*stackSize + stackIndex[stackNum]] = 0;
    stackIndex[stackNum]--;
    return true;
  }

  int peek(int stackNum){
    return arr[stackNum*stackSize + stackIndex[stackNum]];
  }
};

int main(){
  threeStack stack(3);
  stack.display();
  stack.push(5,0);
  stack.display();
  stack.push(3,1);
  stack.display();
  stack.push(2,0);
  stack.display();
  stack.push(1,2);
  stack.display();
  cout << stack.peek(1) << endl;
  stack.pop(1);
  stack.display();

  return 0;
}