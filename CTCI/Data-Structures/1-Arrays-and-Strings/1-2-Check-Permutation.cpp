#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

/*
// O(n*log(n)) solution with sorting
bool checkPermutation(string a, string b){
    if (a.length()!=b.length()){
        return false;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for (int i=0;i<a.length();i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}
*/

// O(n) solution like previous 1-1-Is-Unique, assuming ASCII
bool checkPermutation(string a, string b){
    if (a.length()!=b.length()){
        return false;
    }
    // initialize 128 bit vector with 0 value
    vector<int> set_vec(128,0);
    for (int i=0;i<a.length();i++){
        // increment the previous value if a character is found to keep it's count
        set_vec[int(a[i])]++;
    }
    for (int i=0;i<b.length();i++){
        // increment the previous value if a character is found to keep it's count
        set_vec[int(b[i])]--;
        if (set_vec[i]<0){
            return false;
        }
    }
    for (int i=0;i<set_vec.size();i++){
        // check if any element is 0
        if (set_vec[i]!=0){
            return false;
        }
    }
    return true;
}

int main(){
    string a,b;
    cout << "Enter two strings:\n";
    cin >> a >> b;
    if (checkPermutation(a,b)){
        cout << "Permutation detected" << endl;
    }
    else{
        cout << "No permutation detected" << endl;
    }
    return 0;
}