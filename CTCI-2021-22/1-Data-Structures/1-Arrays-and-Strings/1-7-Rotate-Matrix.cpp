#include <iostream>
#include <stdlib.h>
#include<time.h>
#include <vector>

using namespace std;

void display(vector<vector<int>> matrix){
  for (int i=0; i<matrix.size(); i++){
    for (int j=0; j<matrix[0].size(); j++){
      cout << matrix[i][j] << ", ";
    }
    cout << endl;
  }
}

vector<vector<int>> getMatrix(int row, int col){
  srand(time(0));
  vector<vector<int>> matrix;
  for (int i=0; i<row; i++){
    vector<int> matrix_row;
    for (int j=0; j<col; j++){
      matrix_row.push_back(rand()%10);      
    }
    matrix.push_back(matrix_row);
  }
  return matrix;
}

// without using 2D vector
// time complexity O(n^2)
// space complexity O(1)
vector<vector<int>> rotateMatrix(vector<vector<int>> &a){
  int top;
  for(int i=0;i<a.size()/2;i++){
    // setting up first and last element of each row iteration
    int first = i;
    int last = a.size() - i-1;
    for(int j=first;j<last;j++){
      // offset indicates the j displacement from first element
      int offset = j-first;
      // temporary_variable = top
      top = a[first][j];
      // top = left
      a[first][j] = a[last-offset][first];
      // left = bottom
      a[last-offset][first] = a[last][last-offset];
      // bottom = right
      a[last][last-offset] = a[j][last];
      // right = temporary_variable
      a[j][last] = top;
    }
  }
  return a;
}


/*
// using another 2D vector
// time complexity O(n^2)
// space complexity O(n^2)
vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix){
  int row, col;
  row = matrix.size();
  col = matrix[0].size();
  vector<vector<int>> rotated_matrix(row, vector<int> (col, 0));

  for (int i=0; i<row; i++){
    for (int j=0; j<col; j++){
      // cout << i << "," << j << "->" << j << "," << (col-i-1) << endl;
      rotated_matrix[j][col-1-i] = matrix[i][j];
    }
  }
  return rotated_matrix;
}
*/

int main(){
  int N = 4;
  vector<vector<int>> matrix = getMatrix(N, N);
  cout << "Original matrix : " << endl;
  display(matrix);
  cout << "Rotated matrix : " << endl;
  display(rotateMatrix(matrix));
  return 0;
}