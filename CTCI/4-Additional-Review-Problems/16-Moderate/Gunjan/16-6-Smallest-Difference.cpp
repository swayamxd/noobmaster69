#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void display(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << ",";
    }
    cout << endl;
}

void generateRandomArray(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        arr[i] = rand()%(arr.size()*10);
    }
}

// time complexity O(a*log(a)+b*log(b))
int findSmallestDifference(vector<int> first, vector<int> second){
    int minDistance = INT16_MAX;
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    for(int i=0,j=0,k=0;i<max(first.size(),second.size());i++){
        if (second[k] >= first[j]){
            minDistance = min(minDistance,second[k] - first[j]);
            j++;
        }
        if (first[j] >= second[k]){
            minDistance = min(minDistance,first[j]-second[k]);
            k++;
        }
        if(minDistance==0) break;
    }
    return minDistance;
}

int main(){
    vector<int> firstArray(10);
    vector<int> secondArray(20);
    generateRandomArray(firstArray);
    generateRandomArray(secondArray);
    display(firstArray);
    display(secondArray);
    cout << "Minimum distance: " << findSmallestDifference(firstArray,secondArray) << endl;
    return 0;
}