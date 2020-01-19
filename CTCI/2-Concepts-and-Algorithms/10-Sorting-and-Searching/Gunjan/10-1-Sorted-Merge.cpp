#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<vector>
using namespace std;

void display(vector<int> list){
    for(auto x:list){
        cout << x << " ; ";
    }
    cout << endl;
}

vector<int> generateRandomList(int length){
    srand(time(0));
    vector<int> unSortedList;
    for(int i=0;i<length;i++){
        unSortedList.push_back(rand()%length);
    }
    sort(unSortedList.begin(),unSortedList.end());
    return unSortedList;
}

void merge(vector<int> &sortedListA, vector<int> &sortedListB){
    int endIndexA = sortedListA.size()-1;
    int endIndexB = sortedListB.size()-1;
    sortedListA.resize(sortedListA.size()+sortedListB.size());
    int endIndexNewA = sortedListA.size()-1;
    while(endIndexB>=0){
        if(sortedListB[endIndexB] < sortedListA[endIndexA]){
            sortedListA[endIndexNewA] = sortedListA[endIndexA];
            endIndexA--;
        } else {
            sortedListA[endIndexNewA] = sortedListB[endIndexB];
            endIndexB--;
        }
        endIndexNewA--;
    }
}

int main(){
    int lengthA = 10;
    int lengthB = 7;
    vector<int> sortedListA = generateRandomList(lengthA);
    vector<int> sortedListB = generateRandomList(lengthB);
    display(sortedListA);
    display(sortedListB);
    merge(sortedListA,sortedListB);
    display(sortedListA);
    return 0;
}