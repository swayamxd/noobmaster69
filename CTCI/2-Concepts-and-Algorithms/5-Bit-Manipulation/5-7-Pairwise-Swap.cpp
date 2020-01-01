#include<iostream>
using namespace std;

int pairwiseSwap(int num){
    // 0xAA denotes 1010 1010 in 8 bit
    // as 'A' in hexadecimal converts to '10' in decimal, '1010' in binary
    // leading 0x means it's a hexadecimal number, similarly,
    // 0x55 denotes 0101 0101 in 8 bit
    // as '5' in hexadecimal converts to '5' in decimal, '0101' in binary
    // for 32 bit representation, we will repeat 'A' and '5' 8 times (8*4=32 bit)

    // shift all even bits once to right, shift all odd bits once to left
    // to do this, we need the above mentioned masks

    return (((num & 0xAAAAAAAA) >> 1) | ((num & 0x55555555) << 1));
}

int main(){
    int num = 10;
    cout << pairwiseSwap(num) << endl;
    return 0;
}