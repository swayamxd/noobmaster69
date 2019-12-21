#include<iostream>
#include<vector>
#include<string>
using namespace std;

// O(n) solution
string URLify(string a){
    string result;
    for (int i=0;i<a.length();i++){
        if (isspace(a[i])){
            result+="%20";
        }
        else{
            result+=a[i];
        }
    }
    return result;
}

int main(){
    string a;
    cout << "Enter string: ";
    // cin can't take space separated input, so using getline
    getline(cin,a);
    cout << URLify(a) <<endl;
    return 0;
}