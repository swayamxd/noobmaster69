#include<iostream>
#define max(a,b) ((a>b)?a:b);
using namespace std;

int maxOccuranceOnes(int num){
    if (num==0) return 0;
    int maxOccurance=1;
    int previousLength = 0;
    int currentLength = 0;
    while(num){
        if(num&1 == 1){
            currentLength++;
        } else {
            previousLength = currentLength;
            currentLength=0;
        }
        maxOccurance = max(previousLength+currentLength+1,maxOccurance);
        num = num >> 1;
    }
    return maxOccurance;
}

int main(){
    int num = 1775;
    cout << maxOccuranceOnes(num) << endl;
    return 0;
}