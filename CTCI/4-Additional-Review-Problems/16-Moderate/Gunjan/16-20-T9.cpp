#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
using namespace std;

template<typename T>
void display(vector<T> vec){
    for(T x:vec){
        cout << "'" << x << "',";
    }
    cout << endl;
}

void getWordsWithLength(vector<string> &validWordList, int wordLength){
    ifstream file("words.txt");
    string word;
    while (getline(file, word)){
        // as last char of each line is '\n', so we have to remove that
        word = word.substr(0,word.length()-1);
        if(word.length()==wordLength){
            validWordList.push_back(word);
        }
    }
}

vector <string> generateT9Table(){
    vector <string> t9Table(26);
    for(int i=0,j=2,count=0;i<26;++i){
        t9Table[i] = to_string(j);
        count++;
        if (j != 7 && j != 9 && count == 3 || j == 7 && count == 4 || j == 9 && count == 4){
            j++;
            count=0;
        }
    }
    return t9Table;
}

string changeWordToNumeric (vector<string> &t9Table, string &word){
    string numericRepresentation;
    for(char x:word){
        numericRepresentation += t9Table[int(x)-int('a')];
    }
    return numericRepresentation;
}

// O(n) runtime using unordered_map
vector<string> checkWhichWord(vector<string> &validWordList, string &digitCombination){
    unordered_map <string,vector<string>> numericToWordMap;
    vector <string> t9Table = generateT9Table();
    for(string word: validWordList){
        numericToWordMap[changeWordToNumeric(t9Table,word)].push_back(word);
    }
    return numericToWordMap[digitCombination];
}

int main(){
    string digitCombination = "82733";
    vector<string> validWordList;
    getWordsWithLength(validWordList, digitCombination.length());
    // display(validWordList);
    vector<string> resultWordList = checkWhichWord(validWordList,digitCombination);
    cout << digitCombination << " : ";
    display(resultWordList);
    return 0;
}