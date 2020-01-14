#include<iostream>
using namespace std;

void display(int screen[6][32]){
    for(int i=0;i<6;i++){
        for(int j=0;j<32;j++){
            if(j%8==0) cout << " ";
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }
}

void drawLine(int screen[6][32], int width, int x1, int x2, int y){
    for(int i=x1;i<x2;i++){
        screen[y-1][i] = 1;
    }
}

int main(){
    int screen[6][32] = {0};
    int width = 32; // multiple of 8
    int y = 4;
    int x1 = 35;
    int x2 = 60;
    cout << "Before: " << endl;
    display(screen);
    drawLine(screen,width,x1,x2,y);
    cout << "After: " << endl;
    display(screen);
    return 0;
}