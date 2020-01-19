#include<iostream>
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
    return unSortedList;
}

void merge(vector<int> &unSortedList, vector<int> helperList, int low, int mid, int high){
    //copy everything to helper list
    for(int i=low;i<=high;i++){
        helperList[i]=unSortedList[i];
    }
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high){
        if(helperList[i]<=helperList[j]){
            unSortedList[k] = helperList[i];
            i++;
        } else {
            unSortedList[k] = helperList[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
            unSortedList[k] = helperList[i];
            i++;k++;
    }
    // we don't actually need this loop as unSortedList already has the right ones there
    while(j<=high){
            unSortedList[k] = helperList[j];
            j++;k++;
    }
}

void mergeSort(vector<int> &unSortedList, vector<int> helperList, int low, int high){
    if(low < high) {
        int mid = low + (high-low)/2;
        mergeSort(unSortedList,helperList,low,mid);
        mergeSort(unSortedList,helperList,mid+1,high);
        merge(unSortedList,helperList,low,mid,high);
    }
}

void mergeSort(vector<int> &unSortedList){
    vector<int> helperList (unSortedList.size());
    mergeSort(unSortedList,helperList,0,unSortedList.size()-1);
}

int main(){
    int length = 100;
    vector<int> unSortedList = generateRandomList(length);
    // display(unSortedList);
    mergeSort(unSortedList);
    display(unSortedList);
    return 0;
}