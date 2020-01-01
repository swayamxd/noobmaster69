#include<iostream>
using namespace std;

int flipsRequired(int first, int second){
    int count = 0;
    int intermediate = first^second;
    while(intermediate) {
        if(intermediate & 1) count++;
        intermediate = intermediate >> 1;
    }
    return count;
}

int main(){
    int first = 29;
    int second = 15;
    cout << flipsRequired(first,second) << endl;
    return 0;
}