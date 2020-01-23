#include<iostream>
#include<cmath>
#include<vector>
#include<unordered_map>
#define point pair<float,float>
#define x first
#define y second
using namespace std;

class Line{
public:
    // y = mx+c where
    // m=(y2-y1)/(x2-x1)
    // c = 2y1-y2-2mx1+mx2
    int m,c;
    Line(point a, point b){
        m = round((b.y-a.y)/(b.x-a.x));
        c = round((2*a.y)-(b.y)-(2*m*a.x)+(m*b.x));
    }
    bool operator==(const Line &line2) const{
        return (m==line2.m && c==line2.c);
    }
};

class LineHashFunction{
public:
    // calculate hash for custom class line
    size_t operator()(const Line &line) const{
        return (line.c^line.m);
    }
};

void display(vector<point> pointsList){
    for(int i=0;i<pointsList.size();i++){
        cout << "(" << pointsList[i].x << "," << pointsList[i].y << "); ";
    }
    cout << endl;
}

void generateRandomCoordinates(int totalPoints,vector<point> &coordinates){
    point randomPoint;
    for(int i=0;i<totalPoints;i++){
        randomPoint.x = rand()%totalPoints;
        randomPoint.y = rand()%totalPoints;
        coordinates[i] = randomPoint;
    }
}

Line findBestLine(vector<point>&coordinates){
    unordered_map<Line,int,LineHashFunction> lineFreqTable;
    for(int i=0;i<coordinates.size();i++){
        for(int j=i+1;j<coordinates.size();j++){
            Line currentLine(coordinates[i],coordinates[j]);
            lineFreqTable[currentLine]++;
        }
    }
    Line maxFoundLine(coordinates[0],coordinates[1]);
    int maxCommonPointCount = 0;
    for(auto x:lineFreqTable){
        if(maxCommonPointCount<x.second){
            maxFoundLine = x.first;
            maxCommonPointCount = x.second;
        }
    }
    return maxFoundLine;
}

vector<point> findPointsPassingThroughLine(Line &line, vector<point>&coordinates){
    vector<point> passingPointsList;
    for(point coordinate:coordinates){
        if(coordinate.y == (line.m*coordinate.x)+line.c){
            passingPointsList.push_back(coordinate);
        }
    }
    return passingPointsList;
}

int main(){
    int totalPoints = 10;
    vector<point> coordinates(totalPoints);
    generateRandomCoordinates(totalPoints,coordinates);
    cout << "All generated coordinates : " << endl;
    display(coordinates);
    Line bestLine = findBestLine(coordinates);
    cout << "Line is : Y = " << bestLine.m << "X + " << bestLine.c << endl;
    vector<point> passingPointsList = findPointsPassingThroughLine(bestLine,coordinates);
    cout << passingPointsList.size() << " passing points are : " << endl;
    display(passingPointsList);
    return 0;
}