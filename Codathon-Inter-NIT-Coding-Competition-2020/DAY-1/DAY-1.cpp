#include<iostream>
using namespace std;

int main(){
    int bookCount,maxChapter;
    cin >> bookCount >> maxChapter;
    int library[bookCount];
    for(int i=0;i<bookCount;i++){
        cin >> library[i];
    }
    int i=0,j=bookCount-1;
    while(true){
        if(library[i]>maxChapter && library[j]>maxChapter)
            break;
        if(library[i]<=maxChapter){
            i++;
            bookCount--;
        }
        if(library[j]<=maxChapter){
            j--;
            bookCount--;
        }
    }

    cout << bookCount << endl;
    return 0;
}