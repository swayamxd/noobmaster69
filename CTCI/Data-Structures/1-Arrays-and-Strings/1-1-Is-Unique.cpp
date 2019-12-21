#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

/*
// Brute force O(n^2) solution
bool isUnique(string str){
    for (int i=0;i<str.length();i++){
        for (int j=i+1;j<str.length();j++){
            if (str[i]==str[j]){
                return false;
            }
        }
    }
    return true;
}

// O(n*log(n)) solution with sorting
bool isUnique(string str){
    sort(str.begin(),str.end());
    for (int i=0;i<str.length()-1;i++){
        if (str[i]==str[i+1]){
            return false;
        }
    }
    return true;
}
*/

// O(n) solution:
// If input string is ASCII it will take 128 bits
// If input string is ASCII extended it will take 256 bits
// Taking as ASCII

bool isUnique(string str){
    //initalizing bit vector of size 128 bit with every element as false
    vector<bool> str_flag(128,false);
    for (int i=0;i<str.length();i++){
        // if previously the position is true, then it is duplicate
        if (str_flag[int(str[i])]){
            return false;
        }
        // else as new character found, mark index as true
        else{
            str_flag[int(str[i])] = true;
        }
    }
    return true;
}

int main(){
    string str;
    cout << "Enter string: ";
    cin >> str;
    if (isUnique(str)){
        cout << "Every character is unique" << endl;
    }
    else{
        cout << "Every character is not unique" << endl;
    }
    return 0;
}
