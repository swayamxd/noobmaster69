#include<iostream>
#include<string>
using namespace std;

string stringCompression(string str){
    string result;
    int count = 1;
    for(int i=0;i<str.size();i++){
        if (str[i+1]==str[i]){
            count++;
        } else {
            result += str[i];
            result += to_string(count);
            count = 1;
        }
    }
    if (result.size()<str.size()){
        return result;
    }
    return str;
}

int main(){
    string str;
    cout << "Enter string: ";
    cin >> str;
    cout << stringCompression(str) << endl;
    return 0;
}