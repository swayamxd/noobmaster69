#include <iostream>
#include <string>

using namespace std;

// time complexity O(n)
// space complexity O(1)
bool checkWays(string first, string second){
  // if the lengths differ more than one, then more than one edit required
  if ((((int)first.size()-(int)second.size()) > 1) || 
      (((int)second.size()-(int)first.size()) > 1)) {
    return false;
  }
  // replacement check 
  if (first.size()==second.size()) {
    int edit_flag = 0;
    for (int i=0; i<first.size(); i++){
      if (first[i]!=second[i]) edit_flag++;
      if (edit_flag>1) return false;
    }
  }
  // insertion check 
  if ((int)first.size()>(int)second.size()){
    int edit_flag = 0;
    for (int i=0,j=0; i<first.size(); i++,j++){
      if (first[i]!=second[j]) {
        j--;
        edit_flag++;
      }
      if (edit_flag>1) return false;
    } 
  } 
  // removal check 
  else if ((int)first.size()<(int)second.size()){
    int edit_flag = 0;
    for (int i=0,j=0; j<second.size(); i++,j++){
      if (first[i]!=second[j]) {
        i--;
        edit_flag++;
      }
      if (edit_flag>1) return false;
    }
  }

  return true;
}

int main(){
  string first = "ple";
  string second = "pale";
  cout << (checkWays(first, second)? "true" : "false") << endl;
  return 0;
}