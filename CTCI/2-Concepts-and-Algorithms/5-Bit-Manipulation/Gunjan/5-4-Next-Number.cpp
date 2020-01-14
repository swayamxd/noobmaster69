#include<iostream>
using namespace std;

int findNumberofSetBits(int num){
    int count = 0;
    while(num){
        if (num&1==1) count++;
        num = num >> 1;
    }
    return count;
}

// Brute force solution
pair<int,int> findNextSameSetBits(int num){
    pair<int,int> result;
    result.second = result.first = num;
    int currentSetBits = findNumberofSetBits(num);
    while(currentSetBits != findNumberofSetBits(++result.first))
    while(currentSetBits != findNumberofSetBits(--result.second)) ;
    return result;
}

int main(){
    int num = 10000;
    cout << findNextSameSetBits(num).first << " , " << findNextSameSetBits(num).second << endl;
    return 0;
}