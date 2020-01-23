#include<iostream>
#include<algorithm>
#define point pair<float,float>
#define random rand()%sizeLimit
#define x first
#define y second
using namespace std;

template<typename T>
T max(T a, T b, T c, T d){
    if(a>=b && a>=c && a>=d) return a;
    else if(b>=a && b>=c && b>=d) return b;
    else if(c>=a && c>=b && c>=d) return c;
    else if(d>=a && d>=b && d>=c) return d;
    return d;
}

template<typename T>
T min(T a, T b, T c, T d){
    if(a<=b && a<=c && a<=d) return a;
    else if(b<=a && b<=c && b<=d) return b;
    else if(c<=a && c<=b && c<=d) return c;
    else if(d<=a && d<=b && d<=c) return d;
    return d;
}

class square{
    public:
    point a,b,c,d;
    point mid(){
        int x = max(a.x, b.x, c.x, d.x) - min(a.x, b.x, c.x, d.x);
        int y = max(a.y, b.y, c.y, d.y) - min(a.y, b.y, c.y, d.y);
        return make_pair(x/2,y/2);
    }
};

class line{
    public:
    point a,b;
};

square generateRandomSquare(int sizeLimit){
    /*
    d -- c
    |    |
    a -- b
    */
    square sq;
    sq.a.x = random;
    sq.a.y = random;
    sq.b.x = random + sq.a.x;
    sq.b.y = sq.a.y;
    sq.c.x = sq.b.x;
    sq.c.y = random + sq.b.y;
    sq.c.x = sq.a.x;
    sq.c.y = sq.c.y;
    return sq;
}

line getLine(square &sq1, square &sq2){
    line resultLine;
    resultLine.a = sq1.mid();
    resultLine.b = sq2.mid();
    return resultLine;
}

int main(){
    int sizeLimit = 10;
    square sq1 = generateRandomSquare(sizeLimit);
    square sq2 = generateRandomSquare(sizeLimit);
    line bisection = getLine(sq1,sq2);
    cout << "Bisection line Coordinates: " <<
         "(" << bisection.a.x << "," << bisection.a.y << ") , ("
         << bisection.b.x << "," << bisection.b.y << ")" << endl;
    return 0;
}