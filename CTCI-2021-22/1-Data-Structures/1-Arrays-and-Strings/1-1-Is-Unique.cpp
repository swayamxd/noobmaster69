#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

/*
// using brute force
// time complexity O(n^2)
// space complexity O(1)
bool isUnique(string s){
  sort(s.begin(), s.end());
  for (int i=0; i<s.size(); i++){
    for (int j=i+1; j<s.size(); j++){
      if (s[i]==s[j]) {
        return false;
      }
    }
  }
  return true;
}

// using sorting
// time complexity O(nlogn)
// space complexity O(1)
bool isUnique(string s){
  sort(s.begin(), s.end());
  for (int i=0; i<s.size()-1; i++){
    if (s[i]==s[i+1]) return false;
  }
  return true;
}

// using hash table
// time complexity O(n)
// space complexity O(n)
bool isUnique(string s){
  set<char> s_table;
  for (int i=0; i<s.size(); i++){
    if (s_table.find(s[i]) != s_table.end()){
      return false;
    } else {
      s_table.insert(s[i]);
    }
  }
  return true;
}
*/

// using vector of size 256
// time complexity O(n)
// space complexity O(1)
bool isUnique(string s){
  vector<bool> str_flag (256, false);
  for (int i=0; i<s.size(); i++){
    if (str_flag[int(s[i])]) return false;
    str_flag[int(s[i])] = true;
  }
  return true;
}


int main(){
	string input;
	cout << "Enter your string : ";
  cin >> input;
  cout << (isUnique(input)? "Unique" : "Not Unique") << endl;
	return 0;
}