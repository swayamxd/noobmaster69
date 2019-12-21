#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

// O(n) solution using unordered_map(hash_map)
bool palindromePermutation(string str){
    int oddCounter = 0;
    unordered_map<char,int> palindromeTable;
    for (int i=0;i<str.length();i++){
        if (!isspace(str[i])){
            palindromeTable[str[i]]++;
        }
    }
    for (auto i:palindromeTable){
        if (i.second & 1){
            oddCounter++;
        }
        if (oddCounter > 1){
            return false;
        }
    }
    return true;
}

int main(){
    string str;
    cout << "Enter string : ";
    getline(cin,str);
    if (palindromePermutation(str)){
        cout << "Palindrome is possible" <<endl;
    } else{
        cout << "Palindrome is not possible" <<endl;
    }
    return 0;
}