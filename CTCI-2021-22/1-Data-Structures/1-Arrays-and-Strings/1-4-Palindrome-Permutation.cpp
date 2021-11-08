#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// using hash map
// time complexity O(n)
// space complexity O(n)
bool isPermutation(string s){
  unordered_map <char, int> char_table;
  // if palindrome, then maximum 1 element can be of odd number
  int check_flag = 0;
  for (int i=0; i<s.size(); i++){
    if (s[i]!=' ') char_table[s[i]]++;
  }
  for (auto i: char_table){
    if (i.second & 1) check_flag++;
    if (check_flag>1) return false;
  }
  return true;
}


int main(){
  string s;
  cout << "Enter string : ";
  getline(cin, s);
  cout << (isPermutation(s) ? "Permutation" : "Not permutation") << endl;
  return 0;
}