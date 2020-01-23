#include<iostream>
#include<unordered_map>
using namespace std;

pair<int,int> guess(string computer, string player){
    unordered_map<char,int> computerMap;
    unordered_map<char,int> playerMap;
    int hit=0, pseudoHit=0;
    for(int i=0;i<computer.length();i++){
        // if characters are in the same position, then hit
        if (player[i] == computer[i]) hit++;
        // if characters are not in the same position,
        // then store those character frequencies in map
        // to count pseudoHits from minimim of 2 same characters Freq count
        else {
            computerMap[computer[i]]++;
            playerMap[player[i]]++;
        }
    }
    for(auto x:computerMap){
        // pseudoHit will only happen for the minimum frequency of same characters
        pseudoHit += min(x.second,playerMap[x.first]);
    }
    return make_pair(hit,pseudoHit);
}

int main(){
    string computer = "BGGB";
    string player = "GYRB";
    pair<int,int> result = guess(computer,player);
    cout << "Hit : " << result.first << ", Pseudo hit : " << result.second << endl;
    return 0;
}