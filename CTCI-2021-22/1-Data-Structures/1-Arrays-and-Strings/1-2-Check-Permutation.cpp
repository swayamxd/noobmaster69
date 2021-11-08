#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

/*
// using sorting
// time complexity O(nlogn)
// space complexity O(1)
bool checkPermutation(string first, string second){
  sort(first.begin(), first.end());
  sort(second.begin(), second.end());
  return (first==second);
}
*/

// using hash map
// time complexity O(n)
// space complexity O(n)
bool checkPermutation(string first, string second){
  map<char, int> second_map;
  for (int i=0; i<second.size(); i++){
    second_map.insert(make_pair(second[i],second_map[second[i]]++));
  }
  for (int i=0; i<first.size(); i++){
    second_map[first[i]]--;
    if (second_map[first[i]]<0) return false;
  }
  return true;
}


int main(){
  string first, second;
  cout << "Enter first string : ";
  cin >> first;
  cout << "Enter second string : ";
  cin >> second;
  cout << (checkPermutation(first, second) ? 
    "Permutation" : "Not permutation") << endl;
  return 0;
}