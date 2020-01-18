#include<iostream>
#include<vector>
using namespace std;
#define absoluteDifference(x,y) (x>y) ? (x-y) : (y-x)

void display(vector<vector<int>> &arrangements){
    int arrangementNum=1;
    cout << "size : " << arrangements.size() << endl;
    for(auto arrangement:arrangements){
        cout << "\nArrangement : " << arrangementNum << endl << "\t";
        for(auto column:arrangement){
            for(int i=0;i<arrangement.size();i++){
                if(i==column) cout << "#";
                else cout << "-";
            }
            cout << endl << "\t";
        }
        arrangementNum++;
    }
    cout << endl;
}

bool check(int row, int column, vector<int>& currentBoard){
    for(int i=0;i<row;i++){
        // check if all columns are distinct
        if(currentBoard[i]==column) {
            return false;
        }
        // check if no queens are in diagonals
        // if (row1-row == col1-col) return false
        if((row-i)==(absoluteDifference(column,currentBoard[i]))) {
            return false;
        }
    }
    return true;
}

void eightQueen(int row,int boardSize,vector<int> &currentBoard,vector<vector<int>>& queenArrangements){
    // base case where all rows are filled
    if (row==boardSize) {
        queenArrangements.push_back(currentBoard);
    } else {
        // for each column at certain row
        for (int column=0; column<boardSize; column++) {
            // check in which column the queen can be placed
            if (check(row,column,currentBoard)) {
                // place queen at the column where check succeeds
                currentBoard[row] = column;
                // recurse for the next row
                eightQueen(row+1,boardSize,currentBoard,queenArrangements);
            }
        }
    }
}

vector<vector<int>> eightQueen(int boardSize){
    vector<vector<int>>queenArrangements;
    vector<int> currentBoard;
    currentBoard.resize(boardSize);
    eightQueen(0,boardSize,currentBoard,queenArrangements);
    return queenArrangements;
}

int main(){
    int boardSize = 8;
    vector<vector<int>> queenArrangements = eightQueen(boardSize);
    display(queenArrangements);
    return 0;
}