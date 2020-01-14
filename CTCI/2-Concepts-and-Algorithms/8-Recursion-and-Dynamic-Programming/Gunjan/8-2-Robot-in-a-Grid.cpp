#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<unordered_set>
using namespace std;

// hash function for pair
struct hash_pair{
    template<typename T1, typename T2>
    size_t operator () (const pair <T1,T2>& p) const {
        auto hashT1 = hash<T1>()(p.first);
        auto hashT2 = hash<T2>()(p.second);
        return hashT1^hashT2;
    }
};

void display1D(vector<pair<int,int>> vec){
    if(vec.size()==0) cout << "No way found";
    for(int i=vec.size()-1;i>=0;i--){
        cout <<  " (" << vec[i].first << " , " << vec[i].second << ") ;";
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

// helper method for dynamic programming
bool findWay(vector<vector<bool>> &grid, int startRow, int startColumn,
        vector<pair<int,int>>&way, unordered_set<pair<int,int>, hash_pair>&alreadyVisited) {

    if(startRow == grid.size()-1 && startColumn == grid[0].size()-1)
        return true;
    if(startRow >= grid.size() || startColumn >= grid[0].size() || grid[startRow][startColumn]==false)
        return false;

    // if path is not visited
    if(alreadyVisited.find(make_pair(startRow+1, startColumn))==alreadyVisited.end()){
        // visit the path
        alreadyVisited.insert(make_pair(startRow+1, startColumn));
        // if that path has solution
        if(findWay(grid, startRow+1, startColumn, way, alreadyVisited)) {
            // append that to our way
            way.push_back(make_pair(startRow+1, startColumn));
            return true;
        }
    }
    // if path is not visited
    if(alreadyVisited.find(make_pair(startRow, startColumn+1))==alreadyVisited.end()){
        // visit the path
        alreadyVisited.insert(make_pair(startRow, startColumn+1));
        // if that path has solution
        if(findWay(grid, startRow, startColumn+1, way, alreadyVisited)) {
            // append that to our way
            way.push_back(make_pair(startRow, startColumn+1));
            return true;
        }
    }
    return false;
}

// Dynamic programming O(row*column) solution
vector<pair<int,int>> dpFindWay (vector<vector<bool>> grid){
    vector<pair<int,int>> way;
    unordered_set <pair<int,int>,hash_pair> alreadyVisited;
    if(grid.size()!=0)
        findWay(grid,0,0,way,alreadyVisited);
    return way;
}


// helper method for brute force solution
bool findWay(vector<vector<bool>> &grid, int startRow, int startColumn, vector<pair<int,int>>&way) {
    if(startRow == grid.size()-1 && startColumn == grid[0].size()-1)
        return true;
    if(startRow >= grid.size() || startColumn >= grid[0].size() || grid[startRow][startColumn]==false)
        return false;
    if(findWay(grid, startRow+1, startColumn, way)) {
        way.push_back(make_pair(startRow+1, startColumn));
        return true;
    }
    if(findWay(grid, startRow, startColumn+1, way)) {
        way.push_back(make_pair(startRow, startColumn+1));
        return true;
    }
    return false;
}

// brute force O(2^(row+column)) solution
vector<pair<int,int>> bruteFindWay (vector<vector<bool>> grid){
    vector<pair<int,int>> way;
    if(grid.size()!=0)
        findWay(grid,0,0,way);
    return way;
}

int main(){
    // int row = 10;
    // int column = 30;
    int row = 1000;
    int column = 3000;
    vector<vector<bool>> grid (row, vector<bool> (column, true));
    randomize(grid,row,column);
    // display2D(grid);
    cout << "Way is : " << endl;
    display1D(dpFindWay(grid));
    // display1D(bruteFindWay(grid));
    return 0;
}