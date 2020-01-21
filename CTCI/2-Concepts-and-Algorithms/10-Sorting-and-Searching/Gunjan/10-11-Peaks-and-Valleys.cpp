#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void display(vector<int> &randomList){
    for(auto x: randomList){
        cout << x << ";";
    }
    cout << endl;
}

vector<int> generateRandomList(int length){
    vector<int> randomList(length);
    while(length--){
        randomList[length] = rand()%randomList.size();
        // randomList[length] = length;
    }
    return randomList;
}

void swap(int &a,int &b){
    // let's think how to swap without temporary variable
    // a = 5 , b = 7 then called swap (a,b)
    // a = 5+7 = 12
    // b = 12-7 = 5
    // a = 12-5 = 7
    // now a = 7 , b = 5
    a = a+b;
    b = a-b;
    a = a-b;
}

// return index of the maximum element among adjacent 3 elements
int max(vector<int>&randomList, int prev, int curr, int next){
    if(randomList[prev]>randomList[curr] && randomList[prev]>randomList[next]) return prev;
    else if (randomList[curr]<randomList[next]) return next;
    else return curr;
}

// O(n) solution using 3 pointer
// in adjacent 3 elements the middle one should be peak
void peakValley(vector<int> &randomList){
    for(int curr=1;curr<randomList.size();curr+=2){
        int maxIndex = max(randomList,curr-1,curr,(curr+1)%randomList.size());
        if(curr!=maxIndex) swap(randomList[maxIndex],randomList[curr]);
    }
}

/*
// O(n*log(n)) solution using sorting
// and merging elements from both ends
void peakValley(vector<int> &randomList){
    sort(randomList.begin(),randomList.end());
    vector<int> randomListCopy (randomList);
    for(int i=0,j=randomList.size()-1,k=0;k<randomList.size();k++){
        if(k&1){
            randomList[k] = randomListCopy[i];
            i++;
        } else {
            randomList[k] = randomListCopy[j];
            j--;
        }
    }
}

// O(n*log(n)) solution using sorting and swapping every
// odd indexed elements with its previous even indexed element
void peakValley(vector<int> &randomList){
    sort(randomList.begin(),randomList.end());
    for(int i=1;i<randomList.size();i+=2){
        swap(randomList[i-1],randomList[i]);
    }
}
*/

int main(){
    int length = 11;
    vector<int> randomList = generateRandomList(length);
    display(randomList);
    peakValley(randomList);
    display(randomList);
    return 0;
}