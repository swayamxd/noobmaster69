#include<iostream>
#include<vector>
using namespace std;

void display(vector<string> list){
    for(string str:list){
        cout << str << " ; ";
    }
    cout << endl;
}

vector<string> getListOfStr(){
    vector<string> listOfStr {
        "at",
        "",
        "",
        "",
        "ball",
        "",
        "",
        "car",
        "",
        "",
        "dad",
        "",
        "",
    };
    return listOfStr;
}

int findNearestIndex(vector<string>&list, int index, int low, int high){
    int nearestIndex=index;
    for(int i=index+1,j=index-1;i<=high || j>=low;i++,j--){
        if(i<=high && list[i].length()>0){
            nearestIndex = i;
            break;
        } else if(j>=low && list[j].length()>0){
            nearestIndex = j;
            break;
        }
    }
    return nearestIndex;
}

int search(vector<string> &list,string key, int low, int high){
    if(high>low){
        int mid = low + (high-low)/2;
        // while string at index mid is blank, find nearest non blank index
        while(list[mid].length()==0){
            mid = findNearestIndex(list,mid,low,high);
        }
        if(list[mid]==key) return mid;
        else if (list[mid]>key) {
            return search(list,key,low,mid-1);
        } else {
            return search(list,key,mid+1,high);
        }
    }
    return -1;
}

int search(vector<string> &list,string key){
    return search(list,key,0,list.size()-1);
}

int main(){
    vector<string> listOfStr = getListOfStr();
    string key = "ball";
    display(listOfStr);
    int index = search(listOfStr,key);
    (index>=0) ?
        cout << key << " found at index : " << index << endl :
        cout << key << " not found" << endl;
    return 0;
}