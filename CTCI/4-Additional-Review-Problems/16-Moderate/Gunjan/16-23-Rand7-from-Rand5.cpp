#include<iostream>
using namespace std;

int rand5(){
    return (rand()%5);
}

int rand7(){
    int result;
    while(true){
        result = 7*rand5()+rand5();
        if(result<35){
            result = result%7;
            break;
        }
    }
    return result;
}

int main(){
    cout << rand7() << endl;
    return 0;
}