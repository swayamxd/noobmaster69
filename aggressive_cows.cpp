/*We can use binary search in the function . We first of all sort the stalls.
Then we always keep cow 1 in stall 1 and then proceed by finding the lower_bound in array of stalls for last_stall+dist.

If the lower_bound doesn't point to the end then we can accomodate one more cow.And
then check how many cows can we accomodate with minimum distance dist and 
if it's greater than or equal to the cows present c then it would return true but if noot return false


In step 1- we place 1st cow in stall 1 and last cow in stall n(last stall). then to put one more cow ,
find the middle positiion as this will be farthest from the two other cows.
now check if we keep distance of x(middle) between the cows, is it possible to accomodate all the cows?
if yes then this is the final answer else we further divide middle position( similar divide and conquer concept) and continue 
the steps...
*/
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n,c;
int func(int num,int array[])
{
    int cows=1,pos=array[0];
    for (int i=1; i<n; i++)
    {
        if (array[i]-pos>=num)
        {
            pos=array[i];
            cows++;
            if (cows==c)
                return 1;
        }
    }
    return 0;
}
int bs(int array[])
{
    int ini=0,last=array[n-1],max=-1;
    while (last>ini)
    {
        //cout<<last<<" "<<ini<<endl;
        int mid=(ini+last)/2;
        if (func(mid,array)==1)
        {
            //cout<<mid<<endl;
            if (mid>max)
                max=mid;
            ini=mid+1;
        }
        else
            last=mid;
    }
    return max;
}
int main()
{
    int t;
    cin>>t
    while (t--)
    {
        cin>>n>>c;
        int array[n];
        for (int i=0; i<n; i++)
            cin>>array[i];
        sort(array,array+n);
        
        int k=bs(array);
        cout<<k;
    }
    return 0;
}
