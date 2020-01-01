#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> list){
    for(auto i=list.begin();i!=list.end();i++)
        cout << (*i) << " ; ";
    cout << endl;
}

vector<int> powerOfTwo(int minLimit, int maxLimit){
    vector<int> powerOfTwoList;
    for(int i=minLimit+1;i<maxLimit;i++){
        if ((i&(i-1))==0){
            powerOfTwoList.push_back(i);
        }
    }
    return powerOfTwoList;
}

int main(){
    int minLimit = 0;
    int maxLimit = 20000;
    display(powerOfTwo(minLimit,maxLimit));
    // check if a number id power of 2
    // int checkNum = 40;
    // ((checkNum&(checkNum-1))==0) ? cout << "yes" << endl : cout << "no" << endl;
    return 0;
}