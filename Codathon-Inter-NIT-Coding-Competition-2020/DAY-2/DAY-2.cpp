#include<iostream>
#include<vector>
using namespace std;

void query(vector<int> &matrix, vector<int> &row){
    for(int i=row[0]-1;i<row[1];i++){
        matrix[i] = matrix[i] ^ row[2];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int matrixSize,sum=0,temp;
    long long int querySize;
    cin >> matrixSize;
    vector<int> matrix;
    vector<int> row;
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixSize;j++){
            cin >> temp;
            if(i==j) matrix.push_back(temp);
        }
    }
    cin >> querySize;
    for(long long int i=0;i<querySize;i++){
        for(int j=0;j<4;j++){
            cin >> temp;
            if(j>0)
                row.push_back(temp);
        }
        query(matrix,row);
        row.clear();
    }
    for(int i=0;i<matrixSize;i++){
        sum+=matrix[i];
    }
    cout << sum << endl;
    return 0;
}