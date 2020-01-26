#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class pairHashFunct{
    public:
    size_t operator()(const pair<int,int> &p) const {
        return p.first^p.second;
    }
};

void display(unordered_set<pair<int,int>,pairHashFunct> sumSet){

    if (sumSet.empty()){
        cout << "No sum pair found" << endl;
        return;
    } else {
        cout << "Sum pairs:" << endl;
        for(auto x:sumSet){
            cout << "(" << x.first << "," << x.second << ")" << endl;
        }
    }
}

void display(vector<int> vec){
    for(int x:vec){
        cout << x << ",";
    }
    cout << endl;
}

void generateRandomArray(vector<int> &vec){
    for(int i=0;i<vec.size();i++){
        vec[i] = rand()%vec.size();
    }
}

// O(n*log(n)) solution using sorting
unordered_set<pair<int,int>,pairHashFunct> findPairSumSort(vector<int> array, int requiredSum){
    sort(array.begin(),array.end());
    int currSum;
    int first = 0;
    int last = array.size() - 1;
    unordered_set<pair<int,int>, pairHashFunct> sumSet;
    while(first<last){
        currSum = array[first]+array[last];
        if(currSum==requiredSum){
            sumSet.insert(make_pair(array[first],array[last]));
            first++;
            last--;
        } else if (currSum<requiredSum) {
            first++;
        } else if (currSum>requiredSum) {
            last--;
        }
    }
    return sumSet;
}

// O(n) solution using unordered_set
unordered_set<pair<int,int>,pairHashFunct> findPairSumSet(vector<int> array, int requiredSum){
    int target;
    unordered_set<pair<int,int>, pairHashFunct> sumSet;
    unordered_set<int> arrayCopy;
    for(int i=0;i<array.size();i++){
        target = requiredSum-array[i];
        if(arrayCopy.find(target)==arrayCopy.end()) arrayCopy.insert(array[i]);
        else {
            sumSet.insert(make_pair(array[i],target));
        }
    }
    return sumSet;
}

int main(){
    int requiredSum = 10;
    int arrayLength = 10;
    vector<int> randomArray(arrayLength);
    generateRandomArray(randomArray);
    display(randomArray);
    display(findPairSumSet(randomArray, requiredSum));
    display(findPairSumSort(randomArray, requiredSum));
    return 0;
}