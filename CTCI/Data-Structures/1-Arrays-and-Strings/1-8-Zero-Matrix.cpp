#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

// O(n) solution using unordered_set
void makeZero(vector<vector<int>>& a){
    unordered_set<int> x;
    unordered_set<int> y;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){
            if (a[i][j]==0){
                x.insert(i);
                y.insert(j);
            }
        }
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){
            if (x.find(i)!=x.end()){
                a[i][j]=0;
            } else if (y.find(j)!=y.end()){
                a[i][j]=0;
            }
        }
    }
    return;
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
    vector<vector<int>> matrix {{1,2,1,0},
                                {3,1,4,5},
                                {7,0,8,9},
                                {5,4,2,0}};
    cout << "Entered matrix :" << endl;
    display(matrix);
    cout << "Zeroed matrix :" << endl;
    makeZero(matrix);
    display(matrix);
    return 0;
}