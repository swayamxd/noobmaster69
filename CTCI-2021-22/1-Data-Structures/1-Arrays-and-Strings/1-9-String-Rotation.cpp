#include <iostream>
#include <string>

using namespace std;

bool ifSubstring(string s1, string s2){
  s1 += s1;
  for (int i=0, j=0; i< s1.size(); i++){
    while (s1[i]==s2[j]){
      i++;
      j++;
      if (j==s2.size()) return true;
      if (i==s1.size()) return false;
    } 
    if (s1[i]!=s2[j]) j=0;
  }
  return false;
}

int main(){
  string s1, s2;
  s1 = "waterbottle";
  s2 = "erbottlewat";
  cout << (ifSubstring(s1, s2)? "Sub String" : "Not sub string") << endl;
  return 0;
}