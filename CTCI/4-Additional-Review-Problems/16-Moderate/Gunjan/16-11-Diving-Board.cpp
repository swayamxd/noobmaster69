#include<iostream>
#include<vector>
#define short 5
#define long 10
using namespace std;

void display(vector<int> listOfLengths){
    for(auto x: listOfLengths){
        cout << x << " ";
    }
    cout << endl;
}

void generateAllLengths(vector<int>& listOfLengths){
    for(int i=0;i<listOfLengths.size();i++){
        listOfLengths[i] = i*short + (listOfLengths.size()-i-1)*long;
    }
}

int main(){
    int pickUpCount = 10;
    vector<int> listOfLengths(pickUpCount+1);
    generateAllLengths(listOfLengths);
    display(listOfLengths);
    return 0;
}