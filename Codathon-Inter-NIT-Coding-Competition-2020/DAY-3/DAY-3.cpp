#include<iostream>
#include<vector>
using namespace std;

unsigned long long int permute(int &targetSum, int &divisor, vector<int> &elements){
    long long int result;


    return result;
}

int main(){
    int targetSum,divisor,elementCount,temp;
    cin >> targetSum >> divisor >> elementCount;
    vector<int> elements;
    for(int i=0;i<elementCount;i++){
        cin >> temp;
        elements.push_back(temp);
    }
    cout << permute(targetSum,divisor,elements) << endl;
    return 0;
}