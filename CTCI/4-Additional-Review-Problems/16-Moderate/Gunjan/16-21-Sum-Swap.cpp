#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

template<typename T>
void display(vector<T> array){
    for(T x:array){
        cout << x << ";";
    }
    cout << endl;
}

void generateRandomArray(vector<int> &array){
    for(int i=0;i<array.size();i++){
        array[i] = rand()%array.size();
    }
}

// O(m+n) runtime, which is the best possible runtime that can be achieved
pair<int,int> swapToEqualSum(vector<int> &firstArray, vector<int> &secondArray){
    int firstIndex=-1,secondIndex=-1;
    int sumFirst=0,sumSecond=0;
    unordered_map<int,int> secondArrayCopy;
    for(int i=0;i<firstArray.size();i++){
        sumFirst += firstArray[i];
    }
    for(int i=0;i<secondArray.size();i++){
        sumSecond += secondArray[i];
        secondArrayCopy[secondArray[i]] = i;
    }
    int target;
    for(int i=0;i<firstArray.size();i++){
        target = firstArray[i] - (sumFirst - sumSecond) / 2;
        if(secondArrayCopy[target]>0){
            firstIndex = i;
            secondIndex = secondArrayCopy[target];
            break;
        }
    }
    return make_pair(firstIndex,secondIndex);
}

int main(){
    int firstArrayLength = 10;
    int secondArrayLength = 9;
    vector<int> firstArray(firstArrayLength);
    vector<int> secondArray(secondArrayLength);
    generateRandomArray(firstArray);
    generateRandomArray(secondArray);
    display(firstArray);
    display(secondArray);
    pair<int,int> swapIndices = swapToEqualSum(firstArray,secondArray);
    (swapIndices.first != -1 && swapIndices.second != -1)?
        cout << "Swap indices: (" << swapIndices.first << "," << swapIndices.second << ")" << endl:
        cout << "Not found" << endl;
    return 0;
}