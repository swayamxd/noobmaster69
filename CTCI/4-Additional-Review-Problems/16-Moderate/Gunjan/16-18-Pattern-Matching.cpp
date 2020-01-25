#include<iostream>
#include<vector>
using namespace std;

string checkPattern(string &pattern, string &value, int aCount, int bCount, int a, int b){
    string resultString = "";
    if((a*aCount + b*bCount)==value.size()){
        for(int i=0;i<pattern.size();i++){
            if(pattern[i]=='a')
                resultString += value.substr(resultString.size(),resultString.size()+a);
            else if(pattern[i]=='b')
                resultString += value.substr(resultString.size(),resultString.size()+b);
        }
    }
    return resultString;
}

bool matchPattern (string &pattern, string &value){
    if(pattern.size()==0) return (value.size()==0);
    else if(value.size()==0) return (pattern.size()==0);
    int size = value.size();
    string resultString;
    int aCount=0,bCount=0;
    for(int i=0;i<pattern.size();i++){
        if(pattern[i]=='a') aCount++;
        if(pattern[i]=='b') bCount++;
    }
    if ((aCount == 0 && bCount == 1) || (aCount == 1 && bCount == 0)) return true;
    for (int a = 0; a < size / aCount; a++){
        for (int b = 0; b < size / bCount; b++){
            if(pattern[0]=='a')
                resultString = checkPattern(pattern, value, aCount, bCount, a, b);
            else if (pattern[0] == 'b')
                resultString = checkPattern(pattern, value, bCount, aCount, b, a);
            // if (resultString.size()) cout << resultString << endl;
            if(resultString == value) return true;
        }
    }
    return false;
}

void matchPattern(vector<string> &pattern, string &value){
    for(int i=0;i<pattern.size();i++){
        (matchPattern(pattern[i],value))?
            cout << "Pattern matched : " << pattern[i] << endl:
            cout << "Pattern not matched : " << pattern[i] << endl;
    }
}

int main(){
    vector<string> pattern {
        "aabab",
        "ab",
        "aba",
        "a",
        "b",
    };
    string value = "catcatgocatgo";
    matchPattern(pattern,value);
    return 0;
}