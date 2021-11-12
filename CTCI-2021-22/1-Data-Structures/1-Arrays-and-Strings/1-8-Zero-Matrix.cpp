#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<vector<int>> get_matrix (int row, int col){
  srand(time(0));
  vector<vector<int>> m (row, vector<int>(col, 0));
  for (int i=0; i<row; i++){
    for (int j=0; j<col; j++){
      m[i][j] = rand()%10;
    }
  }
  return m;
}

void display(vector<vector<int>> &m){
  for (int i=0; i<m.size(); i++){
    for (int j=0; j<m[0].size(); j++){
      cout << m[i][j] << ", ";
    }
    cout << endl;
  }
  cout << "--" << endl;
}

/*
// using unordered_set 
// time complexity O(n^2) 
// space complexity O(n) 
void zeroMatrix(vector<vector<int>> &m){
  unordered_set<int> row, col;
  for (int i=0; i<m.size(); i++){
    for (int j=0; j<m[0].size(); j++){
      if (m[i][j] == 0){
        row.insert(i);
        col.insert(j);
      }
    }
  }
  for (int i=0; i<m.size(); i++){
    for (int j=0; j<m[0].size(); j++){
      if (row.find(i)!=row.end() || col.find(j)!=col.end()){
        m[i][j] = 0;
      }
    }
  }
}
*/

// using in place flagging
// time complexity O(n^2) 
// space complexity O(1) 
void zeroMatrix(vector<vector<int>> &m){
  bool rowHasZero = false;
  bool colHasZero = false;
  for (int i=0; i<m.size(); i++){
    for (int j=0; j<m[0].size(); j++){
      if (m[i][j] == 0){
        if (i==0) rowHasZero = true;
        if (j==0) colHasZero = true;
        m[i][0] = 0;
        m[0][j] = 0;
      }
    }
  }
  for (int i=1; i<m.size(); i++){
    for (int j=1; j<m[0].size(); j++){
      if (m[i][0] == 0 || m[0][j] == 0){
        m[i][j] = 0;
      }
    }
  }
  if (rowHasZero){
    for (int i=0; i<m[0].size(); i++){
      m[0][i] = 0;
    }
  }
  if (colHasZero){
    for (int i=0; i<m.size(); i++){
      m[i][0] = 0;
    }
  }
}

int main(){
  int row = 4;
  int col = 5;
  vector<vector<int>> m = get_matrix(row, col);
  cout << "Original Matrix" << endl;
  display(m);
  zeroMatrix(m);
  cout << "Zero Matrix" << endl;
  display(m);
  return 0;
}