/*
Approach-1 Recursion
*/

#include <bits/stdc++.h> 
bool subset(int idx,int target, vector<int> &arr)
{
    if(target==0) return true;
    if(idx==0)
    {
        if(arr[idx]==target) return true;
        else return false;
    }
    
    bool notake= subset(idx-1,target,arr);
    bool take=false;
    if(target>=arr[idx])
    {
        take=subset(idx-1,target-arr[idx],arr);
    }
    return take||notake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return subset(n-1,k,arr);
}
/*
TC: O(2^n) -- for every idx we have 2 option take or notake thereby 2*2*2..
Sc: O(N) - recurisve stack space
*/


/*
Approach-2 Memoization
*/

#include <bits/stdc++.h> 
bool subset(int idx,int target, vector<int> &arr, vector<vector<int>>&dp)
{
    if(target==0) return true;
    if(idx==0)
    {
        if(arr[idx]==target) return true;
        else return false;
    }
    if(dp[idx][target]!=-1) return dp[idx][target];
    bool notake= subset(idx-1,target,arr,dp);
    bool take=false;
    if(target>=arr[idx])
    {
        take=subset(idx-1,target-arr[idx],arr,dp);
    }
    return dp[idx][target]= take||notake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    /*
    since we are passing subset fn as k times so we need one extra for target thereby we called it k+1 times (0,1,2...k==k+1) 
    and in n we have called subset as n-1 times so (0,1,2,3...n-1==n) hence we need n*k+1 size array , one index extra for values we pass.
    */
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return subset(n-1,k,arr,dp);
}

/*
TC: O(N* target)
SC: O(N* target)+O(N)-recursive
*/


/*
Approach-3 Tabulation
*/

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    /*
    We have not written bool dp[n][k+1] becoz we need to initialize the whole table by 0 so that everytime a new value comes that 
    cell will be overridden otherwise the cell will be 0 which were meant to be.
    made dp of N*K+1 becoz f(n-1,target) so idx will be from 0->n-1 and target will be from 0->k 
    */
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++)
    {
        // for every index i if target is 0 then we got an empty subset so it's also a subset that we want hence it's true.
        dp[i][0]=true;
    }
    if(arr[0]<=k) dp[0][arr[0]]=true; //at idx=0 , if our target is arr[0] then it will be true
    
    /*
    for two states (idx,target) we'll have 2 nested loops idx will run from 1->n-1 and target will be from 1->k
    */
    for(int idx=1;idx<n;idx++)
    {
        for(int target=1;target<=k;target++)
        {
            bool notake=dp[idx-1][target];
            bool take=false;
            if(target>=arr[idx]) take=dp[idx-1][target-arr[idx]];
            dp[idx][target]=take||notake;
        }
    }
    return dp[n-1][k];
}

/*
TC:O(N* target)
SC:O(N* target)
*/

/*
Approach-4 Space Optimization
*/

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
   vector<bool>prev(k+1,0),curr(k+1,0);\
   //the first idx=0 will always be true as it says target is 0 so we got an empty subset
    prev[0]=curr[0]=true;
    if(arr[0]<=k) prev[arr[0]]=true;
    
    //for every row(idx) we are having target cols,so we are computing rows 
    for(int idx=1;idx<n;idx++)
    {
        for(int target=1;target<=k;target++)
        {
            bool notake=prev[target];
            bool take=false;
            if(target>=arr[idx]) take=prev[target-arr[idx]];
            curr [target]=take||notake;
        }
        prev=curr;
    }
    return prev[k];
}

/*
TC:O(N* target)
SC:O(target)
*/