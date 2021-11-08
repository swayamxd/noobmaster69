#include <iostream>
#include <string>
#include <vector>

using namespace std;


// returning a string
// time complexity O(n)
// space complexity O(n)
string urlify(string s){
  string new_s;
  for (int i=0; i<s.size(); i++){
    if (s[i]!=' '){
      new_s += s[i];
    } else {
      new_s += "%20";
    }
  }
  return new_s;
}


int main(){
  string s;
  cout << "Enter string : ";
  getline(cin, s);
  s = urlify(s);
  cout << "URLifyed string : " << s << endl;
  return 0;
}