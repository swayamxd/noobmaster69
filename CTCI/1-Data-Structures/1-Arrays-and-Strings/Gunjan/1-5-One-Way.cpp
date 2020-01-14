#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

// O(n) solution using unordered_map
bool insertRemoval(string big, string small){
    int editCount = 0;
    unordered_map<char,int> editTable;
    for (auto i:big){
        editTable[i]++;
    }
    for (auto i:small){
        if(editTable[i]==0){
            editCount++;
        }
        if(editCount > 1){
            return false;
        }
    }
    return true;
}

bool replace(string a, string b){
    bool counter = false;
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i]){
            if(counter){
                return false;
            }
            counter = true;
        }
    }
    return true;
}

bool oneWay(string a, string b){
    if(a.length()==b.length()){
        return replace(a,b);
    } else if(a.length()==b.length()+1){
        return insertRemoval(a,b);
    } else if(a.length()+1==b.length()){
        return insertRemoval(b,a);
    }
    return false;
}

int main(){
    string a,b;
    cout << "Enter two strings:\n";
    cin >> a >> b;
    if (oneWay(a,b)){
        cout << "One edit away" <<endl;
    } else {
        cout << "More than one edit away" <<endl;
    }
    return 0;
}