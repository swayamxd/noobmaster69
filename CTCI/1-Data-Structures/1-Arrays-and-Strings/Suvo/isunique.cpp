#include <bits/stdc++.h>
using namespace std;

bool isunique(string s){
    int flag = 0;
    vector<char>v(128,false);
    for(int i = 0;i< s.length();i++){
        int val = s[i];
        if(v[val]){
            return false;
        }
        else{
            v[val]= true;
        }
    }
    return true;
}

int main(){
    string s;
    cout << "Enter the string";
    cin  >> s;
    //cout << "this is your string" <<endl;
    if(isunique(s)){
        cout << "string is unique" << endl;

        }
    else{
        cout << "string is not unique" << endl;
    }
return 0;
}
