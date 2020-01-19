#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> list){
    for(auto x:list){
        cout << x << " ; ";
    }
    cout << endl;
}

vector<int> generateList(int length){
    vector<int> list(length*3, -1);
    for(int i=0;i<length;i++){
        list[i] = i+2;
    }
    return list;
}

int search(vector<int> list, int key, int low, int high){
    if(high>low){
        int mid = low + (high-low)/2;
        if(list[low]==key) return low;
        else if(list[mid]==key) return mid;
        else if(list[high]==key) return high;
        // if index mid contains -1 or is greater than key, then search left
        else if(list[mid]>key || list[mid]==-1) return search(list,key,low+1,mid-1);
        // if index mid is less than key, then search right
        else if(list[mid]<key) return search(list,key,mid+1,high-1);
    }
    return -1;
}

int search(vector<int> list, int key){
    if(list[0]==key) return 0;
    // i gets multiplied by 2 at each iteration
    int high = 0;
    for(int i=1;;i<<=1){
        if(list[i]<0) {
            high = i;
            break;
        }
    }
    return search(list,key,0,high);
}

int main(){
    int length = 10;
    int key = length/3;
    vector<int> list = generateList(length);
    display(list);
    int index = search(list,key);
    (index>=0) ?
        cout << "Key found at index : " << index << endl :
        cout << "Key not found" << endl ;
    return 0;
}