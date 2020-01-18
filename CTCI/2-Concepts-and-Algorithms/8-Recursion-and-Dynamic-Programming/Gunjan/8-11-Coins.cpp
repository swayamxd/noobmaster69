#include<iostream>
#include<unordered_map>
using namespace std;

int totalWays(int sum, int cents, int quarters, int dimes, int nickles, int pennies, unordered_map<int,int> cache) {
    // if sum went larger than target cents, then no path found, return 0
    if(sum>cents) return 0;
    // if sum is exactly equal to target cents, then 1 path found, return 1
    else if(sum==cents) return 1;
    // if our cache is empty, we haven't seen this before, so calculate and store in cache
    // so that cache at key sum will return total ways of reaching target
    else if(cache[sum]<=0){
        // totalWays is addition of if we added any of the coins
        cache[sum] = ( totalWays(sum+quarters, cents, quarters, dimes, nickles, pennies, cache) +
                    totalWays(sum+dimes, cents, quarters, dimes, nickles, pennies, cache) +
                    totalWays(sum+nickles, cents, quarters, dimes, nickles, pennies, cache) +
                    totalWays(sum+pennies, cents, quarters, dimes, nickles, pennies, cache) );
    }
    // return way from cache
    return cache[sum];
}

int main(){
    int cents = 50;
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    unordered_map<int,int> cache;
    cout << totalWays(0,cents,quarters,dimes,nickels,pennies,cache) << endl;
    return 0;
}