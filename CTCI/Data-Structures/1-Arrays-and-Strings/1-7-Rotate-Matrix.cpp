#include<iostream>
#include<vector>
using namespace std;

bool rotate(vector<vector<int>>&a){
    if(a.size()!=(a[0].size())) return false;
    // the temporary variable that holds top most swap value
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
    return true;
}

void display(vector<vector<int>>&a){
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){
            cout << " " << a[i][j];
        }
        cout << endl;
    }
    return;
}

int main(){
    vector<vector<int>> matrix {{1,2,3,4},
                                {5,6,7,8},
                                {9,10,11,12},
                                {13,14,15,16}};
    cout << "Entered matrix :" << endl;
    display(matrix);
    cout << "Rotated matrix :" << endl;
    rotate(matrix)?
        display(matrix):
        (void) (cout << "matrix is not square matrix"<< endl);
    return 0;
}