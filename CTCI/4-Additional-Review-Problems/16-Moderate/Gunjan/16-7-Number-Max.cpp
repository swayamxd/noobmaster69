#include<iostream>
using namespace std;

// flips bit
int flip(int x){
    return x^1;
}

// return 1 if x possitive, else returns 0
int sign(int x){
    return (flip(x >> 31) & 1);
}

int getMax(int a,int b){
    int k = sign(a-b);
    int q = flip(k);
    // if (a-b)>=0 then k=1, and q=0 then returns a
    // if (a-b) <0 then k=0, and q=1 then returns b
    return k*a + q*b;
}

int main(){
    int a=10;
    int b=5;
    cout << "Maximum is : " << getMax(a,b) << endl;
    return 0;
}