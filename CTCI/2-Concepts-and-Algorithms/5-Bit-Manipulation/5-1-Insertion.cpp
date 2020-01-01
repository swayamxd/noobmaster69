#include<iostream>
using namespace std;

int updateBits(int first, int second, int i, int j){
    // MSB till j is all 1's from left
    int left = ~0 << j ;
    // LSB till i is all 1's from right
    int right = ~(~0 << i) ;
    // merge left and right in mask
    // this mask has all 1's except from i to j, they are 0
    int mask = left | right;
    // add padding to second
    int result = (first & mask) | (second << i);
    return result;
}

int main(){
    int firstNum = 1024;
    int secondNum = 19;
    int i=2, j=6;
    cout << updateBits(firstNum,secondNum,i,j) << endl;
    return 0;
}