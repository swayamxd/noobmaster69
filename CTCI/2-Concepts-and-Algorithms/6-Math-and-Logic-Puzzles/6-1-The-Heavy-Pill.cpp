#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

int findHeavyPill(vector<double> bottles){
    int bottleNum;
    // let's take 1 pill from bottle 1, 2 pills from bottle 2...bottle
    // 20 pills from bottle 20, so total weight should be: (21*20/2)
    double targetWeight = bottles.size()*(bottles.size()+1)/2;
    // currentWeight is checked by the same method above
    double currentWeight = 0;
    for(int i=1;i<=bottles.size();i++){
        currentWeight += bottles[i-1]*i;
    }
    // bottleNum will be calculated by:
    bottleNum = (currentWeight - targetWeight)/0.1;
    return (bottleNum-1);
}

int main(){
    vector<double> bottles;
    for(int i=0;i<20;i++){
        bottles.push_back(1);
    }
    int randomBottleNum = rand()%20;
    bottles[randomBottleNum] = 1.1;
    cout << randomBottleNum << " = " << findHeavyPill(bottles) << endl;
    return 0;
}