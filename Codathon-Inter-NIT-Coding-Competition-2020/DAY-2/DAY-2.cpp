#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int matrixSize,sum=0,temp;
    long int querySize;
    cin >> matrixSize;
    int matrix[matrixSize];
    int row[3];
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixSize;j++){
            cin >> temp;
            if(i==j) matrix[i] = (temp);
        }
    }
    cin >> querySize;
    for(long int i=0;i<querySize;i++){
        for(int j=0;j<4;j++){
            cin >> temp;
            if(j>0)
                row[j-1] = temp;
        }
        for(int i=row[0]-1;i<row[1];i++){
            matrix[i] ^= row[2];
        }
    }
    for(int i=0;i<matrixSize;i++){
        sum+=matrix[i];
    }
    cout << sum << endl;
    return 0;
}