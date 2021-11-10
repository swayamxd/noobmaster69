#include <iostream>
#include <string>

using namespace std;

string compress(string s){
  if (s.size()<=2){
    return s;
  }
  string compressed_s;
  int count = 1;
  for (int i=0; i<s.size(); i++){
    if(s[i+1]==s[i]){
      count++;
    } else {
      compressed_s += s[i];
      compressed_s += to_string(count);
      count = 1;
    }
  }
  cout << compressed_s << " , " << s << endl;
  return ((compressed_s.size()<s.size()) ? compressed_s : s);
}

int main(){
  string s;
  cout << "Enter string : ";
  getline(cin, s);
  cout << "Compressed : " << compress(s) << endl;
  return 0;
}