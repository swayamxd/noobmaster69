#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

void display(unordered_set<string> permutations){
    for(auto i: permutations){
        cout << i << endl;
    }
}

void display(vector<string> permutations){
    for(auto i: permutations){
        cout << i << endl;
    }
}

// generate random string with some duplicate characters
string generateStrWithDups(int length){
    string strWithDups;
    for(int i=0;i<length;i++){
        // strWithDups += char(rand()%26+int('a'));
        strWithDups += "aa";
    }
    return strWithDups;
}

vector<string> permuteString(unordered_map<char,int> &chrTable){
    vector<string> permutations;
    bool baseCase = true;
    for(auto x:chrTable){
        if(x.second>0){
            baseCase = false;
            chrTable[x.first]--;
            vector<string> intermediate = permuteString(chrTable);
            chrTable[x.first]++;
            for (auto y:intermediate){
                permutations.push_back(x.first+y);
            }
        }
    }
    if(baseCase){
        permutations.push_back("");
    }
    return permutations;
}

vector<string> permuteString(string strWithDups){
    unordered_map<char,int> chrTable;
    // building the hash table of character frequency/count
    for(char c:strWithDups){
        chrTable[c]++;
    }
    return permuteString(chrTable);
}

/*
// using a hash table instead of vector removes duplicates, but doesn't
// save time. Worst case time is still O(n!) like the previous problem
unordered_set<string> permuteString(string strWithDups){
    int len = strWithDups.length();
    unordered_set<string> permutations;
    // base case where strWithDups is null
    if(len==0){
        permutations.insert("");
        return permutations;
    }
    // partial permutation of first (n-1) characters of strWithDups string
    unordered_set<string> partialPermutations = permuteString(strWithDups.substr(0,len-1));
    for(auto str:partialPermutations){
        // insert last character at each index of partial permutations
        for(int i=0;i<=str.length();i++){
            // add all inserted strings inside result
            permutations.insert(str.substr(0,i)+strWithDups[len-1]+str.substr(i,len));
        }
    }
    return permutations;
}
*/

int main(){
    int length=20;
    string strWithDups = generateStrWithDups(length);
    // cout << strWithDups <<endl;
    display(permuteString(strWithDups));
    return 0;
}