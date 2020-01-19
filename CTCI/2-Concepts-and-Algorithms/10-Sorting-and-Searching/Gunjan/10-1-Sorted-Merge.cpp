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
    vector<int> sortedListACopy (sortedListA);
    sortedListA.resize(sortedListACopy.size()+sortedListB.size());
    int i,j,k;
    i=j=k=0;
    while(i<sortedListACopy.size() && j<sortedListB.size()){
        if(sortedListACopy[i]<=sortedListB[j]){
            sortedListA[k] = sortedListACopy[i];
            i++;
        } else {
            sortedListA[k] = sortedListB[j];
            j++;
        }
        k++;
    }
    while(i<sortedListACopy.size()){
        sortedListA[k] = sortedListACopy[i];
        i++;
        k++;
    }
    while(i<sortedListB.size()){
        sortedListA[k] = sortedListB[j];
        j++;
        k++;
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