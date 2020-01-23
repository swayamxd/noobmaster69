#include<iostream>
#include<vector>
#define gameDimension 4
#define invalid INT16_MAX
using namespace std;

void display (vector<vector<char>>& ticTacToe){
    for(int i=0;i<ticTacToe.size();i++){
        for(int j=0;j<ticTacToe[0].size();j++){
            cout << ticTacToe[i][j] << "  ";
        }
        cout << endl;
    }
}

void generateTicTacToe(vector<vector<char>>& ticTacToe){
    // vector<char> choices {'X','O',' '};
    vector<char> choices {'X','O'};
    srand(time(0));
    for(int i=0;i<ticTacToe.size();i++){
        for(int j=0;j<ticTacToe[0].size();j++){
            ticTacToe[i][j] = choices[rand()%choices.size()];
        }
    }
}

pair<int,int> checkWhoWon(vector<vector<char>> &ticTacToe){
    char prev,curr;
    int i,j;
    // checking all rows
    for(i=0;i<ticTacToe.size();i++){
        for(j=1;j<ticTacToe[0].size();j++){
            prev = ticTacToe[i][j-1];
            curr = ticTacToe[i][j];
            if(curr != prev) break;
        }
        if(curr==prev) return make_pair(i,j-1);
    }
    // checking all columns
    for(i=0;i<ticTacToe.size();i++){
        for(j=1;j<ticTacToe[0].size();j++){
            prev = ticTacToe[j-1][i];
            curr = ticTacToe[j][i];
            if(curr != prev) break;
        }
        if(curr==prev) return make_pair(j-1,i);
    }
    // checking first diagonal where i==j
    for(i=1;i<ticTacToe.size();i++){
        for(j=1;j<ticTacToe[0].size();j++){
            prev = ticTacToe[i-1][j-1];
            if(i==j) {
                curr = ticTacToe[i][j];
                if(curr != prev) break;
            }
        }
        if(curr==prev) return make_pair(i,j-1);
    }
    // checking first diagonal where i==j
    for(i=1;i<ticTacToe.size();i++){
        for(j=1;j<ticTacToe[0].size();j++){
            prev = ticTacToe[j+1][i-1];
            if(j==ticTacToe[0].size()-1-i) {
                curr = ticTacToe[j][i];
                if(curr != prev) break;
            }
        }
        if(curr==prev) return make_pair(j-1,i);
    }
    return make_pair(invalid,invalid);
}

int main(){
    vector<vector<char>> ticTacToe (gameDimension,vector<char> (gameDimension));
    generateTicTacToe(ticTacToe);
    display(ticTacToe);
    pair<int,int> winnerIndex = checkWhoWon(ticTacToe);
    if(winnerIndex.first == winnerIndex.second == invalid)
        cout << "No one won" << endl;
    else{
        cout << winnerIndex.first << "," << winnerIndex.second << endl;
        char winner = ticTacToe[winnerIndex.first][winnerIndex.second];
        if(winner == 'X') cout << "'X' won" << endl;
        if(winner == 'O') cout << "'O' won" << endl;
        if(winner == ' ') cout << "No one won" << endl;
    }
    return 0;
}