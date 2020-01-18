#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
using namespace std;

void display(vector<vector<char>> &screen){
    for(auto row:screen){
        for(auto element:row){
            cout << element << " ";
        }
        cout << endl;
    }
}

vector<vector<char>> generateScreen(int row, int column){
    srand(time(0));
    vector<char> colourPallete {'V','I','B','G'};
    vector<vector<char>> screen;
    for(int i=0;i<row;i++){
        vector<char> rowVector;
        for(int j=0;j<column;j++){
            rowVector.push_back(colourPallete[rand() % colourPallete.size()]);
        }
        screen.push_back(rowVector);
    }
    return screen;
}

void fillColour(int rowIndex, int columnIndex, char newColour, char oldColour, vector<vector<char>> &screen) {
    if(rowIndex<0 || rowIndex >= screen.size() ||
        columnIndex<0 || columnIndex >= screen[0].size()) {
        return;
    }
    char currColour = screen[rowIndex][columnIndex];
    if(currColour==oldColour){
        screen[rowIndex][columnIndex] = newColour;
        fillColour(rowIndex,columnIndex-1,newColour,oldColour,screen); // left
        fillColour(rowIndex,columnIndex+1,newColour,oldColour,screen); // right
        fillColour(rowIndex-1,columnIndex,newColour,oldColour,screen); // up
        fillColour(rowIndex+1,columnIndex,newColour,oldColour,screen); // down
    }
}

void fillColour(int rowIndex, int columnIndex, char newColour, vector<vector<char>> &screen){
    if(rowIndex<0 || rowIndex >= screen.size() ||
        columnIndex<0 || columnIndex >= screen[0].size()) {
        cout << "indices off bound" << endl;
        return;
    }
    char oldColour = screen[rowIndex][columnIndex];
    fillColour(rowIndex,columnIndex,newColour,oldColour,screen);
}

int main(){
    int row = 4;
    int column = 20;
    vector<vector<char>> screen = generateScreen(row,column);
    display(screen);
    int randomRowIndex = rand()%row;
    int randomColumnIndex = rand()%column;
    fillColour(randomRowIndex,randomColumnIndex,'O',screen);
    cout << endl;
    display(screen);
    return 0;
}