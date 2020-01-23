#include<iostream>
using namespace std;

int countZeros(int n){
    int count=0;
    for(int i=5;n/i>=1;i*=5){
        count += n/i;
    }
    return count;
}

int main(){
    int number = 13;
    cout << "Number of 0s in " << number << "! : " << countZeros(number) << endl;
    return 0;
}