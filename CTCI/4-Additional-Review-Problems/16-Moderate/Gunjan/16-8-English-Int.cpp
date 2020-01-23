#include<iostream>
#include<vector>
using namespace std;

vector<string> smalls {
    "zero","one","two","three","four","five","six","seven","eight","nine","ten",
    "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"
};
vector<string> mids {
    "","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"
};
vector<string> bigs {
    "","thousand","million","billion","trillion"
};

string convertThreeDigits(int num){
    string translated = "";
    if(num>=100){
        translated += smalls[num/100] + " hundred";
        num %= 100;
    }
    if(num>19 && num<100){
        translated += " " + mids[num/10];
        num %= 10;
    }
    if(num>0 && num<20){
        translated += " " + smalls[num];
    }
    return translated;
}

string convert(int num){
    if(num==0) return smalls[0];
    else if(num<0) return "negative "+convert(-1*num);
    string translated = "";
    int countLengthThree = 0;
    while(num){
        translated = convertThreeDigits(num%1000) + " " + bigs[countLengthThree] + " " + translated;
        num/=1000;
        countLengthThree++;
    }
    return translated;
}

int main(){
    int number = 123453030;
    cout << convert(number) << endl;
    return 0;
}