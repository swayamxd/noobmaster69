#include<iostream>
#include<vector>
using namespace std;

void display(vector<string> permutations){
    for(auto i: permutations){
        cout << i << endl;
    }
}

string generateUniqueString(int length){
    string unique;
    for(int i=0;i<length;i++){
        unique += char(i+int('a'));
    }
    return unique;
}

//  Building from permutations of first n-1 characters.
vector<string> permuteString(string unique){
    int len = unique.length();
    vector<string> permutations;
    // base case where unique is null
    if(len==0){
        permutations.push_back("");
        return permutations;
    }
    // partial permutation of first (n-1) characters of unique string
    vector<string> partialPermutations = permuteString(unique.substr(0,len-1));
    for(auto str:partialPermutations){
        // insert last character at each index of partial permutations
        for(int i=0;i<=str.length();i++){
            // add all inserted strings inside result
            permutations.push_back(str.substr(0,i)+unique[len-1]+str.substr(i,len));
        }
    }
    return permutations;
}

/*
//  Building from permutations of all n-1 character substrings.
vector<string> permuteString(string unique){
    int len = unique.length();
    vector<string> permutations;
    // base case where unique string is null
    if(len==0){
        permutations.push_back("");
        return permutations;
    }
    for (int i=0;i<len;i++){
        // splitting the unique string at index i
        string subStringBeforeI = unique.substr(0,i);
        string subStringAfterI = unique.substr(i+1,len);
        // permute whole string except character indexed at i
        vector<string> intermediate = permuteString(subStringBeforeI + subStringAfterI);
        // prepend i th character from unique to all permutations got inside intermediate
        for(auto str:intermediate){
            permutations.push_back(unique[i]+str);
        }
    }
    return permutations;
}
*/

int main(){
    int length=3;
    // cout << generateUniqueString(length) <<endl;
    display(permuteString(generateUniqueString(length)));
    return 0;
}