#include<iostream>
#include<vector>
#include<unordered_set>
#define point pair<int,int>
#define x first
#define y second
using namespace std;

class hashFunctionPoint{
    public:
    size_t operator() (const point &a) const{
        return (a.x * a.y) + (a.x + a.y);
    }
};

class Ant{
    public:
    point antPos = make_pair(0,0);
    string orientation = "right";
    void turnDirection(bool clockWise){
        if(orientation == "down")
            orientation = (clockWise) ? "left" : "right";
        else if(orientation == "right")
            orientation = (clockWise) ? "down" : "up";
        else if(orientation == "up")
            orientation = (clockWise) ? "right" : "left";
        else if(orientation == "left")
            orientation = (clockWise) ? "up" : "down";
    }
    void move(){
        if (orientation=="down") antPos.x++;
        else if (orientation=="right") antPos.y++;
        else if (orientation=="up") antPos.x--;
        else if (orientation=="left") antPos.y--;
    }
};

class board{
    public:
    int moves;
    point topLeft, bottomRight;
    Ant ant;
    unordered_set<point,hashFunctionPoint> whitePoints;
    void makeRandomWhitePoints();
    void display();
    void move();
    void flip(point pos);
    void padBoard(point pos);
    bool isWhite(point pos);
    board(int totalMoves){
        moves = totalMoves;
        makeRandomWhitePoints();
    }
};

void board::padBoard(point pos){
    topLeft.x = min(topLeft.x,pos.x);
    topLeft.y = min(topLeft.y,pos.y);
    bottomRight.x = max(bottomRight.x,pos.x);
    bottomRight.y = max(bottomRight.y,pos.y);
}

void board::flip(point pos){
    if (whitePoints.find(pos) == whitePoints.end()){
        whitePoints.insert(pos);
    } else {
        whitePoints.erase(whitePoints.find(pos));
    }
}

bool board::isWhite(point pos){
    return (whitePoints.find(pos) != whitePoints.end());
}

void board::move(){
    point currentPosition = ant.antPos;
    ant.turnDirection(isWhite(currentPosition));
    flip(currentPosition);
    ant.move();
    padBoard(currentPosition);
}

void board::makeRandomWhitePoints(){
    int randomRow,randomCol;
    for(int i=0;i<moves;i++){
        randomRow = rand()%moves;
        randomCol = rand()%moves;
        whitePoints.insert(make_pair(randomRow,randomCol));
    }
}

void board::display(){
    int minCol = topLeft.x;
    int minRow = topLeft.y;
    int maxCol = bottomRight.x;
    int maxRow = bottomRight.y;
    for(int i=minRow;i<maxRow;i++) {
        for(int j=minCol;j<maxCol;j++) {
            point currentPoint = make_pair(i,j);
            if(i==ant.antPos.x && j==ant.antPos.y) {
                cout << 'A' << "  ";
            } else if(whitePoints.find(currentPoint)!=whitePoints.end()) {
                cout << 'W' << "  ";
            } else {
                cout << 'B' << "  ";
            }
        }
        cout << endl;
    }
}

int main(){
    int totalMoves = 100;
    board newBoard(totalMoves);
    while(--totalMoves)
        newBoard.move();
    newBoard.display();
    return 0;
}