#include<iostream>
#include<algorithm>
#include<vector>
#define invalid 0
using namespace std;

void display(vector<int> &array){
    for(int i=0;i<array.size();i++){
        cout << array[i] << ",";
    }
    cout << endl;
}

void swap(int&a, int&b){
    a = a^b;
    b = a^b;
    a = a^b;
}

vector<int> generate(int length){
    int offset = rand()%length;
    vector<int> array(length);
    for(int i=0;i<length;i++,offset++){
        array[i] = i*offset;
    }
    for(int i=0;i<3;i++){
        int index1 = rand()%length;
        int index2 = rand()%length;
        swap(array[index1],array[index2]);
    }
    return array;
}

// O(n) solution using left,mid,right partition
pair<int,int> findSubSort(vector<int> &array){
    int arrayLen = array.size();
    int startIndex=0, endIndex=arrayLen-1;
    while(startIndex<arrayLen-2 && array[startIndex]<=array[startIndex+1]) startIndex++;
    while(endIndex>0 && array[endIndex]>=array[endIndex-1]) endIndex--;
    if (startIndex >= endIndex)
        return make_pair(invalid, invalid);
    int min=INT16_MAX;
    int max=INT16_MIN;
    for(int i=startIndex;i<endIndex;i++){
        if(min>array[i]) min=array[i];
        if(max<array[i]) max=array[i];
    }
    startIndex=0, endIndex=arrayLen-1;
    while(startIndex<arrayLen-2 && array[startIndex]<min) startIndex++;
    while(endIndex>0 && array[endIndex]>max) endIndex--;
    return make_pair(startIndex,endIndex);
}

/*
// O(n*log(n)) solution using sorting
pair<int,int> findSubSort(vector<int> &array){
    int startIndex=0, endIndex=0;
    vector<int> arrayCopy(array);
    sort(arrayCopy.begin(),arrayCopy.end());
    for(int i=0,j=array.size()-1;i<array.size();i++,j--){
        if(startIndex==0 && array[i]!=arrayCopy[i]) startIndex = i;
        if(endIndex==0 && array[j]!=arrayCopy[j]) endIndex = j;
        if(startIndex!=0 && endIndex!=0) break;
    }
    return make_pair(startIndex,endIndex);
}
*/

int main(){
    int arrayLength = 20;
    vector<int> array = generate(arrayLength);
    display(array);
    pair<int,int> index = findSubSort(array);
    (index.first==invalid && index.second==invalid)?
        cout << "Could not find" << endl:
        cout << "Indices:" << index.first << "," << index.second << endl;
    return 0;
}