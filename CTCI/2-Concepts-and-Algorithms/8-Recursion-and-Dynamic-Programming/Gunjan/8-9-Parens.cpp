#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void display(vector<string> parenthesis){
    for(auto x:parenthesis){
        cout << x << endl;
    }
    cout << "Size: " << parenthesis.size() << endl;
}

void display(unordered_set<string> parenthesis){
    for(auto x:parenthesis){
        cout << x << endl;
    }
    cout << "Size: " << parenthesis.size() << endl;
}

void generateString (int index, int leftParenCount, int rightParenCount,
                    vector<string>& permutations, string validString) {
    // when either leftParenCount<0 or rightParenCount<leftParenCount
    // that means it's invalid state, return
    if(leftParenCount<0 || rightParenCount<leftParenCount) return;
    // when all parenthesis are used, push back the string to list and return
    if(leftParenCount==0 && rightParenCount==0){
        permutations.push_back(validString);
        return;
    } else {
        // left recurse
        validString[index] = '(';
        generateString(index+1,leftParenCount-1,rightParenCount,permutations,validString);
        // right recurse
        validString[index] = ')';
        generateString(index+1,leftParenCount,rightParenCount-1,permutations,validString);
    }
}

vector<string> generateString(int pairCount){
    vector<string> permutations;
    string validString;
    validString.resize(pairCount*2);
    generateString(0,pairCount,pairCount,permutations,validString);
    return permutations;
}

/*
// lots of duplicate calls are made
unordered_set<string> generateString(int pairCount){
    unordered_set<string> parenthesis;
    if(pairCount == 1){
        parenthesis.insert("()");
        return parenthesis;
    }
    unordered_set<string> intermediate = generateString(pairCount-1);
    for(string x:intermediate){
        for (int i=0;i<pairCount;i++){
            parenthesis.insert(x.substr(0,i)+"()"+x.substr(i,x.length()));
        }
    }
    return parenthesis;
}
*/

int main(){
    int pairCount = 3;
    display(generateString(pairCount));
    return 0;
}