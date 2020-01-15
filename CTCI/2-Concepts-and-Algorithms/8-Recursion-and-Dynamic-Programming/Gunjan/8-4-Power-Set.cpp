#include<iostream>
#include<vector>
using namespace std;

// prints sets
void display(vector<vector<int>> powerSet) {
    for(auto x:powerSet){
        cout << "{";
        if (!x.empty()) {
            for(auto y:x){
                cout << y << ";";
            }
        }
        cout << "}" << endl;
    }
}

// generates set of elements
vector<int> generateSet(int elementCount) {
    vector<int> set;
    for(int i=0;i<elementCount;i++){
        set.push_back(i+1);
    }
    return set;
}

// combinatorics helper to find out set value from
// a int by converting it into binary
vector<int> convertIntToSet(vector<int> set, int x) {
    vector<int> convertedSet;
    for(int i=0;i<set.size() && x;i++){
        if(x&1){
            convertedSet.push_back(set[i]);
        }
        x = x >> 1;
    }
    return convertedSet;
}

// using combinatorics :
// take binary numbers starting from
// 0 to m where (m.length() == set.length())
// meaning all kinds of combinations which
// can be represented as binary numbers
vector<vector<int>> powerSetCombinatorics (vector<int> &set){
    vector<vector<int>> powerSet;
    // making 2^n (iteration of powerSet)
    int maxIteration = 1 << set.size();
    while(maxIteration) {
        powerSet.push_back(convertIntToSet(set, maxIteration));
        maxIteration--;
    }
    return powerSet;
}


// using recursion :
// let power set of 2 elements:
// p2 = {},{a1},{a2},{a1,a2}
// let power set of 3 elements:
// p3 = {},{a1},{a2},{a3},{a1,a2},{a2,a3},{a1,a3},{a1,a2,a3}
// so newly added elements are:
// p3-p2 = {a3},{a2,a3},{a1,a3},{a1,a2,a3}
// we can immitate it by cloning p2, then add a3 to all elements:
// p2 = {},{a1},{a2},{a1,a2}
// (p2+a3) = {a3},{a1,a3},{a2,a3},{a1,a2,a3}
// this is exactly same as p3
// so p3 = (p2+a3)
// or more generically:
// p(n) = p(n-1)+a(n)
vector<vector<int>> powerSetRecursion(vector<int> &set, int index){
    vector<vector<int>> powerSet;
    if (index==set.size()) {
        vector<int> empty;
        powerSet.push_back(empty);
    } else {
        powerSet = powerSetRecursion(set,index+1);
        vector<vector<int>> nextSet = powerSet;
        for(int i=0;i<nextSet.size();i++){
            nextSet[i].push_back(index);
        }
        powerSet.insert(powerSet.end(),nextSet.begin(),nextSet.end());
    }
    return powerSet;
}

int main(){
    int elementCount = 10;
    vector<int> set = generateSet(elementCount);
    display(powerSetRecursion(set,0));
    display(powerSetCombinatorics(set));
    return 0;
}