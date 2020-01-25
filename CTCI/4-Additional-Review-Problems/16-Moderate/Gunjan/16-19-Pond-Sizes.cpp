#include<iostream>
#include<vector>
using namespace std;

void display(vector<vector<int>> &plot){
    for(int i=0;i<plot.size();i++){
        for(int j=0;j<plot[0].size();j++){
            cout << plot[i][j] << "  ";
        }
        cout << endl;
    }
}

void display(vector<int> &pond){
    for(int i=0;i<pond.size();i++){
        cout << pond[i] << ",";
    }
    cout << endl;
}

void generateRandomPlot(vector<vector<int>> &plot){
    vector<int> randomPlotHeight {0,1,2};
    for(int i=0;i<plot.size();i++){
        for(int j=0;j<plot[0].size();j++){
            plot[i][j] = randomPlotHeight[rand()%randomPlotHeight.size()];
        }
    }
}

int getSize(vector<vector<int>> &plot, vector<vector<bool>> &visited, int row, int col){
    int size=1;
    visited[row][col] = true;
    // left
    if (col > 0 && plot[row][col-1] == 0 && !visited[row][col-1])
        size += getSize(plot, visited, row, col-1);
    // right
    if (col < plot[0].size()-1 && plot[row][col+1] == 0 && !visited[row][col+1])
        size += getSize(plot, visited, row, col+1);
    // up
    if (row > 0 && plot[row-1][col] == 0 && !visited[row-1][col])
        size += getSize(plot, visited, row-1, col);
    // down
    if (row < plot.size() - 1 && plot [row + 1][col] == 0 && !visited[row + 1][col])
        size += getSize(plot, visited, row+1, col);
    // up left
    if (row > 0 && col > 0 && plot[row - 1][col - 1] == 0 && !visited[row - 1][col - 1])
        size += getSize(plot, visited, row-1, col-1);
    // up right
    if (row > 0 && col < plot[0].size() - 1 && plot [row - 1][col + 1] == 0 && !visited[row - 1][col + 1])
        size += getSize(plot, visited, row-1, col+1);
    // down left
    if (row < plot.size() - 1 && col > 0 && plot[row + 1][col - 1] == 0 && !visited[row + 1][col - 1])
        size += getSize(plot, visited, row+1, col-1);
    // down right
    if (row < plot.size() - 1 && col < plot[0].size() - 1 && plot[row + 1][col + 1] == 0 && !visited[row + 1][col + 1])
        size += getSize(plot, visited, row+1, col+1);
    return size;
}

vector<int> getSize(vector<vector<int>> &plot){
    int size;
    vector<int> pondSizes;
    vector<vector<bool>> visited(plot.size(),vector<bool>(plot[0].size(),false));
    for(int i=0;i<plot.size();i++){
        for(int j=0;j<plot[0].size();j++){
            if(plot[i][j]==0 && !visited[i][j]){
                size = getSize(plot,visited,i,j);
                pondSizes.push_back(size);
            }
        }
    }
    return pondSizes;
}

int main(){
    int row = 4;
    int col = 10;
    vector<vector<int>> plot(row,vector<int> (col));
    generateRandomPlot(plot);
    display(plot);
    vector<int> pondSizes = getSize(plot);
    cout << "Pond sizes: ";
    display(pondSizes);
    return 0;
}