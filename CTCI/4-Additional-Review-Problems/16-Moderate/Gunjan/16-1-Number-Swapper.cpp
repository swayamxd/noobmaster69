#include<iostream>
using namespace std;

// using bitwise xor
void swapWithoutTemp(int&a,int&b){
    a = a^b; // 15
    b = a^b; // 10
    a = a^b; // 5
}

/*
// using arithmetic
void swapWithoutTemp(int&a,int&b){
    a = a+b; // 15
    b = a-b; // 10
    a = a-b; // 5
}
*/

int main(){
    int a=10;
    int b=5;
    cout << "Before : a=" << a << ", b=" << b << endl;
    swapWithoutTemp(a,b);
    cout << "After  : a=" << a << ", b=" << b << endl;
    return 0;
}