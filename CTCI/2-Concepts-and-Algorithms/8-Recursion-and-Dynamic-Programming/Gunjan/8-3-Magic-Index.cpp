#include<iostream>
using namespace std;

void generateList(int *arr, int arraySize, int offset){
    for(int i=0,j=-offset;i<arraySize;i++,j+=2){
        arr[i] = j;
    }
}

bool findMagicIndex(int *arr, int low, int high, int &index){
    if(high<low) return false;
    int mid = low+(high-low)/2;
    if(arr[mid]==mid){
        index = mid;
        return true;
    }
    if(arr[mid]>mid) return findMagicIndex(arr,low,mid-1,index);
    if(arr[mid]<mid) return findMagicIndex(arr,mid+1,high,index);
    return false;
}

int findMagicIndex(int *arr, int arraySize) {
    int index = -1;
    findMagicIndex(arr,0,arraySize-1,index);
    return index;
}

int main(){
    int arraySize = 20;
    int offset = 5;
    int arr[arraySize];
    generateList(arr, arraySize, offset);
    int index = findMagicIndex(arr, arraySize);
    (index>=0) ?
        cout << "Magic index at : " << index << endl :
        cout << "Magic index not found" << endl;

    return 0;
}