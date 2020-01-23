#include<iostream>
#include<algorithm>
#define point pair<float,float>
#define randomNum rand()%100
#define invalid INT16_MAX
#define display(x,y) "("<<x.first<<","<<x.second<<") ; ("<<y.first<<","<<y.second<<")"
using namespace std;

class equation{
    public:
    float a,b,c;
};

void generateRandomCoOrdinates(point &line1First,point &line1Second,
                                point &line2First,point &line2Second) {
    line1First.first = randomNum;
    line1First.second = randomNum;
    line1Second.first = randomNum;
    line1Second.second = randomNum;
    line2First.first = randomNum;
    line2First.second = randomNum;
    line2Second.first = randomNum;
    line2Second.second = randomNum;
    cout << "Coordinates :\n" <<
        "line 1 : " << display(line1First,line1Second) << endl <<
        "line 2 : " << display(line2First,line2Second) << endl;
}

equation createEquationFromCoOrdinate(point firstPoint,point secondPoint){
    equation newEquation;
    // if firstPoint and secondPoint both satisfies the equation
    // ax1+by1 = c and ax2+by2 = c
    // then we can write
    // a = y2-y1
    // b = x1-x2
    // c = ax1+by1
    newEquation.a = secondPoint.second - firstPoint.second;
    newEquation.b = firstPoint.first - secondPoint.first;
    newEquation.c = (newEquation.a * firstPoint.first) - (newEquation.b * firstPoint.second);
    return newEquation;
}

point solveEquation(equation eq1,equation eq2){
    // a1x+b1y = c1
    // a2x+b2y = c2
    // so solving for x and y
    // x = (c1b2-c2b1) / (a1b2-a2b1)
    // y = (a1c2-a2c1) / (a1b2-a2b1)
    // return (x,y)
    // if (a1b2-a2b1)==0, then the lines are parallel
    float determinant,x,y;
    determinant = (eq1.a * eq2.b) - (eq2.a * eq1.b);
    if(determinant==0){
        x = invalid;
        y = invalid;
        cout << "lines are parallel" << endl;
    } else {
        x =  ((eq1.c * eq2.b) - (eq2.c * eq1.b)) / determinant;
        y =  ((eq1.a * eq2.c) - (eq2.a * eq1.c)) / determinant;
        cout << "Intersects at: " << x << "," << y << endl;
    }
    return make_pair(x,y);
}

bool checkIfPossible (point line1First,point line1Second,
                        point line2First,point line2Second,
                        point intersection) {
    // if lines are parallel
    if(intersection.first == intersection.second == invalid)
        return false;
    // if intersection points lies between 2 line segments, return true, else false
    if(min(line1First.first,line2First.first) <= intersection.first &&
        intersection.first <= max(line1First.first,line2First.first) &&
        min(line1First.second,line2First.second) <= intersection.second &&
        intersection.second <= max(line1First.second,line2First.second))
            return true;
    return false;
}

point getIntersection(point line1First,point line1Second,
                        point line2First,point line2Second) {
    equation eq1,eq2;
    eq1 = createEquationFromCoOrdinate(line1First,line1Second);
    eq2 = createEquationFromCoOrdinate(line2First,line2Second);
    point intersection = solveEquation(eq1,eq2);
    return intersection;
}

int main(){
    point line1First,line1Second,line2First,line2Second,intersection;
    generateRandomCoOrdinates(line1First,line1Second,line2First,line2Second);
    intersection = getIntersection(line1First,line1Second,line2First,line2Second);
    bool ifPossible = checkIfPossible(line1First,line1Second,line2First,line2Second,intersection);
    (ifPossible) ?
        cout << "Intersection at : (" << intersection.first << " , " << intersection.second << ")" << endl :
        cout << "Intersection not found between above 2 line segments" << endl ;
    return 0;
}