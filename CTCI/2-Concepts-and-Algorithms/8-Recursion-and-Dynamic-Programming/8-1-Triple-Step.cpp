# include<iostream>
using namespace std;

// dynamic programming helper method
unsigned long long int countWays (int totalSteps, int *cache){
    // exceeded totalSteps, so return 0
    if (totalSteps<0) return 0;
    // ended exactly at totalSteps, so return 1
    else if (totalSteps==1) return 1;
    // if cache is 0, then cache don't have the data
    else if(cache[totalSteps]<=0)
        // return what happens if jumps 1, 2 or 3 steps
        cache[totalSteps] = (countWays(totalSteps-1, cache) + countWays(totalSteps-2, cache) + countWays(totalSteps-3, cache));
    return cache[totalSteps];
}

// applying dynamic programming
unsigned long long int countWays (int totalSteps){
    // initialize array with all 0
    int cache[totalSteps] = {0};
    return countWays(totalSteps, cache);
}

/*
// applying brute force
// O(3^n) solution as the tree is trinary and spanned till depth "n"
unsigned long long int countWays (int totalSteps){
    // exceeded totalSteps, so return 0
    if (totalSteps<0) return 0;
    // ended exactly at totalSteps, so return 1
    else if (totalSteps==1) return 1;
    // else return what happens if jumps 1, 2 or 3 steps
    return (countWays(totalSteps-1) + countWays(totalSteps-2) + countWays(totalSteps-3));
}
*/

int main(){
    int totalSteps = 30000;
    cout << "total ways possible : "
        << countWays(totalSteps) << endl;
    return 0;
}