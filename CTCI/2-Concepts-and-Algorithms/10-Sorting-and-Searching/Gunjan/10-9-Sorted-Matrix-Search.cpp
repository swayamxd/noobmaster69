#include<iostream>
#include<vector>
using namespace std;

void display(vector<vector<int>> matrix){
    for(int i=0,k=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++,k+=5){
        cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

vector<vector<int>> generateSortedMatrix(int row, int column){
    vector<vector<int>> matrix;
    vector<int> eachRow;
    for(int i=0,k=0;i<row;i++,k-=rand()%(row-i+1)*column){
        for(int j=0;j<column;j++,k+=5){
            eachRow.push_back(k);
        }
        matrix.push_back(eachRow);
        eachRow.clear();
    }
    return matrix;
}

// modified binary search
// time complexity O(M*log(N))
pair<int,int> search(vector<vector<int>> matrix, int key){
    pair<int,int> index = make_pair(-1,-1);
    int lastRow = matrix.size()-1;
    int lastColumn = matrix[0].size()-1;
    for(int i=lastRow;i>=0;i--){
        if(matrix[i][0]<=key && key<=matrix[i][lastColumn]){
            int low = 0,mid;
            int high = lastColumn;
            while(high > low){
                mid = low + (high-low)/2;
                if(matrix[i][mid] == key){
                    index = make_pair(i,mid);
                    break;
                } else if(matrix[i][mid] < key) low = mid+1;
                else if(matrix[i][mid] > key) high = mid-1;
            }
        }
    }
    return index;
}

int main(){
    int row = 5;
    int column = 10;
    int key = 45;
    vector<vector<int>> matrix = generateSortedMatrix(row, column);
    display(matrix);
    pair<int,int> index = search(matrix,key);
    (index.first>=0 && index.second>=0) ?
        cout << key << " found at : (" << index.first << "," << index.second << ")" << endl :
        cout << key << " not found." << endl;
    return 0;
}