#include<iostream>
#define negate(x) (-x)
#define abs(x) ((x>0)?x:-x)
using namespace std;

int substract(int a, int b){
    return (a+negate(b));
}

int multiply(int a, int b){
    if(a==0 || b==0) return 0;
    int bigger = (a>b)?a:b;
    int smaller = (a<b)?a:b;
    int resultSign=1,result = 0;
    if(bigger<0 && smaller<0) resultSign = 1;
    else if(bigger<0 || smaller<0) resultSign = -1;
    while(smaller!=0){
        result += abs(bigger);
        (smaller>0) ? smaller--:smaller++;
    }
    return (resultSign==1)?result:(-result);
}

int divide(int a, int b){
    if(abs(b)>abs(a)) return 0;
    else if(b==a) return 1;
    else if(-b==a || b==-a) return -1;
    int resultSign=1,result = 0;
    if(a<0 && b<0) resultSign = 1;
    else if(a<0 || b<0) resultSign = -1;
    int bCopy = abs(b);
    while(bCopy<=abs(a)){
        result++;
        bCopy+=abs(b);
    }
    return (resultSign==1)?result:(-result);
}

int main(){
    int a = -50;
    int b = 10;
    cout << a << " - " << b << " = " << substract(a,b) << endl;
    cout << a << " * " << b << " = " << multiply(a,b) << endl;
    cout << a << " / " << b << " = " << divide(a,b) << endl;
    return 0;
}