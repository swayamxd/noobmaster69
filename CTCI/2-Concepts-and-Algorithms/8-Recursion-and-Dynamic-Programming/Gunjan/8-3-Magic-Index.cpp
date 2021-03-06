#include<iostream>
using namespace std;

void generateList(int *arr, int arraySize, int offset){
    for(int i=0,j=-offset;i<arraySize;i++,j+=2){
        arr[i] = j;
    }
}

int findMagicIndex(int *arr, int low, int high){
    if(high<low) return -1;
    int mid = low+(high-low)/2;
    if(arr[mid]==mid) return mid;
    if(arr[mid]>mid) return findMagicIndex(arr,low,mid-1);
    if(arr[mid]<mid) return findMagicIndex(arr,mid+1,high);
    return -1;
}

int findMagicIndex(int *arr, int arraySize) {
    return findMagicIndex(arr,0,arraySize-1);
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