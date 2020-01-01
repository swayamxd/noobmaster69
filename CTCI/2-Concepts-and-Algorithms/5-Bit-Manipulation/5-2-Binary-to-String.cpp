#include<iostream>
#include<string>
using namespace std;

string binToStr(double num){
    double digit;
    string binary = "0.";
    while(num>0){
        digit = num * 2;
        cout << num << " toBinary: " << binary << endl;
        if (binary.length() > 32) return "ERROR";
        else if (digit>=1) {
            binary.push_back('1');
            num=digit-1;
        } else {
            binary.push_back('0');
            num=digit;
        }
    }
    return binary;
}

int main(){
    double num = 0.5;
    cout << binToStr(num) << endl;
    return 0;
}