#include<iostream>
using namespace std;

class multiStack{
    private:
    int arraySize, stackSize;
    int stackTop[3] = {-1,-1,-1};
    int *array;
    public:
    multiStack(int size){
        arraySize = size;
        array = (int *)malloc(arraySize*sizeof(int));
        stackSize = arraySize/3;
    }
    void display(){
        cout << "Elements of array :" << endl;
        for (int i=0;i<arraySize;i++){
            cout << array[i] << " , ";
        }
        cout << endl;
    }
    void display(int stackNum){
        cout << "Elements of Stack " << stackNum << endl;
        for (int i=0;i<stackSize;i++){
            cout << array[stackNum*stackSize + i] << " , ";
        }
        cout << endl;
    }
    void push(int stackNum, int value){
        stackTop[stackNum]++;
        if(stackTop[stackNum]==stackSize){
            cout << "Buffer overflow at stack " << stackNum << " while inserting " << value << endl;
            return;
        }
        // cout << (stackNum*stackSize) + stackTop[stackNum] <<endl;
        array[(stackNum*stackSize) + stackTop[stackNum]] = value;
        return;
    }
    int peek(int stackNum){
        if(stackTop[stackNum]==-1){
            cout << "Buffer underflow at stack " << stackNum << endl;
            return 0;
        }
        return array[(stackNum*stackSize) + stackTop[stackNum]];
    }
    void pop(int stackNum){
        if(stackTop[stackNum]==-1){
            cout << "Buffer underflow at stack " << stackNum << endl;
            return;
        }
        array[(stackNum*stackSize) + stackTop[stackNum]] = 0;
        stackTop[stackNum]--;
        return;
    }
};

int main(){
    int arraySize = 10;
    multiStack stack(arraySize);
    stack.push(0,5);
    stack.push(1,3);
    stack.push(0,2);
    stack.push(2,1);
    // cout << stack.peek(0) << endl;
    // stack.pop(0);
    // cout << stack.peek(0) << endl;
    // stack.pop(0);
    // cout << stack.peek(0) << endl;
    // stack.pop(0);
    stack.display();
    stack.display(0);
    return 0;
}