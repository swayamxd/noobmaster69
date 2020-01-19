#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

void display(vector<string> stringList){
    for(auto str:stringList){
        cout << str << " ; ";
    }
    cout << endl;
}

vector<string> generateArrayofStrings(){
    vector<string> stringList = {
        "osuv",
        "honey",
        "dgo",
        "oneyh",
        "god",
        "oenyh",
        "suvo",
        "dog"
    };
    return stringList;
}

void groupAnagrams(vector<string> &stringList){
    unordered_map<string,vector<string>> stringMap;
    for(string str:stringList){
        string sortedString = str.substr(0,str.length());
        sort(sortedString.begin(),sortedString.end());
        stringMap[sortedString].push_back(str);
    }
    stringList.clear();
    for(auto x:stringMap){
        for(auto str:x.second){
            stringList.push_back(str);
        }
    }
}

int main(){
    vector<string> stringList = generateArrayofStrings();
    display(stringList);
    groupAnagrams(stringList);
    display(stringList);
    return 0;
}