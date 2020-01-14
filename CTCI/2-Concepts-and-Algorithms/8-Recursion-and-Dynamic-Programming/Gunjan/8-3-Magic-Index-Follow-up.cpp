#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void generateList(int *arr, int arraySize, int offset){
    srand(time(0));
    for(int i=0,j=-offset;i<arraySize;i++,j+=2){
        // randomly set previous value to "j" as per question
        if(rand()%10==i) j-=2;
        arr[i] = j;
    }
}

int findMagicIndex(int *arr, int low, int high){
    if(high<low) return -1;
    int mid = low+(high-low)/2;
    int midValue = arr[mid];
    if(midValue==mid) return mid;
    // to understand this logic, go to CTCI
    // pageNo (pdf(359)/book(347))
    int left = findMagicIndex(arr,low,min(midValue,mid-1));
    if (left>=0) return left;
    int right =  findMagicIndex(arr,max(midValue,mid+1),high);
    return right;
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