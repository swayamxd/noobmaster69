/*Bytelandian gold coins will involve Dynamic Programming. 
The optimal solution for n coins can be obtained by combining the optimal solutions for (n/2), (n/3) and (n/4) coins. 
This property, however, only holds for n>=12. If n<12, the solution will be equal to n, more formally, n > (n/2) + (n/3) + (n/4) 
for all n < 12 and dp[n]=dp[n/2]+dp[n/3]+dp[n/4] for all n>=12, where dp[n] is the optimal solution for n coins.
I’ve used map container for space optimization as n<=1000000000.
*/



    #include<bits/stdc++.h>
    using namespace std;
    map<int,long long> dp;
    long long optcoins(int n){
        if(n<12)
            return n;
        if(dp.count(n))
            return dp[n];
        dp[n]=optcoins(n/2)+optcoins(n/3)+optcoins(n/4);
        return dp[n];
    }
    int main(){
        int x;
        while(cin>>x)
            cout<<optcoins(x);
        return 0;
    }
