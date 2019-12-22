#include<iostream>
#include<string>
using namespace std;

// O(n) solution
bool isSubString(string s1, string s2){
    // concatenate s2, if s1 belongs in s2, we can figure out by looping
    s2 += s2;
    bool match = false;
    for(int i=0,j=0; i<s1.size(); i++,j++){
        // loop s2 while no first match
        if (!match) while(s2[j]!=s1[i]) j++;
        // if any character doesn't match after fisrt match
        if (match) if(s2[j]!=s1[i]) return false;
        // if first character matches
        if (s2[j]==s1[i]) match = true;
    }
    return match;
}

int main(){
    string s1,s2;
    cout << "Enter two strings: " << endl;
    cin >> s1 >> s2;
    isSubString(s1,s2)?
        cout << "Is sub string" << endl:
        cout << "Is not sub string" << endl;
    return 0;
}