#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void display(int *arr,int length){
    for(int i=0;i<length;i++){
        cout << arr[i] << " ; ";
    }
    cout << endl;
}

int * generateRotatedArray(int length){
    srand(time(0));
    int randomNumber = rand();
    int *array = (int *)malloc(sizeof(int)*length);
    for(int i=0,j=length*10;i<length;i++,j+=10){
        array[i] = j;
        if(i == randomNumber%(length-1)) {
            j=i*10;
        }
    }
    return array;
}

int searchArray(int * rotatedArray, int length, int keyToSearch, int low, int high){
    // enter if high is greater than low, else return -1
    if(high>low){
        int mid = low + (high-low)/2;
        if(keyToSearch==rotatedArray[low]) return low;
        else if(keyToSearch==rotatedArray[mid]) return mid;
        else if(keyToSearch==rotatedArray[high]) return high;
        // if left side is properly sorted
        else if(rotatedArray[low]<=rotatedArray[mid]){
            // if key resides between low and mid
            if(rotatedArray[low]<keyToSearch && keyToSearch<rotatedArray[mid]){
                return searchArray(rotatedArray,length,keyToSearch,low+1,mid-1);
            }
            // if key resides between mid and high
            else {
                return searchArray(rotatedArray,length,keyToSearch,mid+1,high-1);
            }
        }
        // if right side is properly sorted
        else if(rotatedArray[mid]<=rotatedArray[high]){
            // if key resides between mid and high
            if(rotatedArray[mid]<keyToSearch && keyToSearch<rotatedArray[high]){
                return searchArray(rotatedArray,length,keyToSearch,mid+1,high-1);
            }
            // if key resides between low and mid
            else {
                return searchArray(rotatedArray,length,keyToSearch,low+1,mid-1);
            }
        }
    }
    return -1;
}

int searchArray(int * rotatedArray, int length, int keyToSearch){
    int low = 0;
    int high = length-1;
    return searchArray(rotatedArray,length,keyToSearch,low,high);
}

int main(){
    int length = 100;
    int keyToSearch = 900;
    int * rotatedArray = generateRotatedArray(length);
    display(rotatedArray,length);
    int index = searchArray(rotatedArray,length,keyToSearch);
    (index>=0) ?
        cout << "Index found at : " << index << endl :
        cout << "Index not found" << endl ;
    return 0;
}