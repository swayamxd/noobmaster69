#include<iostream>
using namespace std;

void putPoison(int *strips, int randomBottleNum){
    int stripNum = 0;
    while(randomBottleNum){
        if (randomBottleNum &1) strips[stripNum] = 1;
        stripNum++;
        randomBottleNum = randomBottleNum >> 1;
    }
}

int getPoisonBottleNum(int *strips,int totalStrips){
    int bottleNum=0;
    for(int i=0;i<totalStrips;i++){
        bottleNum += strips[i] * (1<<i);
    }
    return bottleNum;
}

int main(){
    int totalStrips = 10;
    int totalBottles = 1000;
    // so max of totalBottles count's representation
    // should accomodate under 2^totalStrips bits
    // 1<<totalStrips = 2^totalStrips
    if(1<<totalStrips < totalBottles){
        cout << "Can't accomodate all bottles at once" << endl;
        return 0;
    }
    int strips[10] = {0};
    int randomBottleNum = rand()%totalBottles;
    putPoison(strips,randomBottleNum);
    cout << randomBottleNum << " = " << getPoisonBottleNum(strips,totalStrips) << endl;
    return 0;
}