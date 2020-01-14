#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
using namespace std;

template<typename T>
void display1D(vector<T> vec){
    for(auto x:vec){
        cout << x << " ; ";
    }
    cout << endl;
}

template<typename T>
void display2D(vector<vector<T>> vec){
    for(auto x:vec) {
        for (auto y:x) {
            cout << y << " ; ";
        }
        cout << endl;
    }
}

void randomize (vector<vector<bool>> &grid, int row, int column) {
    srand(time(0));
    for(int i=0;i<row;i++) {
        for (int j=0;j<column;j++) {
            if(rand()%column == j || rand()%column == i) {
                // false means the way is blocked or off limits
                grid[i][j] = false;
            }
        }
    }
}

vector<char> findWay (vector<vector<bool>> &grid){
    vector<char> way;
    if(grid.size()!=0)
        // findWay(grid,0,0,way);
    return way;
}

int main(){
    int row = 10;
    int column = 20;
    vector<vector<bool>> grid (row, vector<bool> (column, true));
    randomize(grid,row,column);
    display2D(grid);
    // display1D(findWay(grid));
    return 0;
}