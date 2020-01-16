#include<iostream>
using namespace std;

// O(log(n)) solution using recursion
// if small number is even, then formula is
// multiply(big,small/2) + multiply(big,small/2)
// ex: multiply(8,6) = multiply(8,3) + multiply(8,3)
// if small number is odd, then formula is
// multiply(big,small/2) + multiply(big,small/2) + big
// ex: multiply(8,7) = multiply(8,3) + multiply(8,3) + 8
int multiplyHelper(int big, int small){
    if(small==0) return 0;
    if(small==1) return big;
    if (small&1)
        // (number/2) can also be written as (number>>1)
        return multiplyHelper(big,small>>1)+multiplyHelper(big,small>>1)+big;
    return multiplyHelper(big,small>>1)+multiplyHelper(big,small>>1);
}

int multiply(int first, int second){
    int bigger, smaller;
    bigger = (first>=second) ? first : second;
    smaller = (first<second) ? first : second;
    return multiplyHelper(bigger,smaller);
}

int main(){
    int first = 1000;
    int second = 200000;
    cout << first  << " X "
         << second << " = "
         << multiply(first,second)
         << endl;
    return 0;
}