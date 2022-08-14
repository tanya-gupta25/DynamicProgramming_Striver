/*
Approach-1 Recursion

*/

#include<bits/stdc++.h>
using namespace std;

// we have made this another function becoz we are using recursion
int maxsum(vector<int> &nums,int idx)
{
    //if index==0 that means we haven't picked idx=1 so we'll pick this element
    if(idx==0) return nums[idx];
    // if idx is out of bounds so return 0
    if(idx<0) return 0;
    int pick=0,nonpick=0;
    // if we picked that element then we can't picked its adjacent so idx-2 because adj will be idx-1 and we'll also add the value of current idx
     pick=maxsum(nums,idx-2)+nums[idx];
    //  if we didn't picked that element then we'll pick adjacent element idx-1 and we will not add the current element as we haven't picked it so add 0.
     nonpick=maxsum(nums,idx-1)+0;
    // now at last return the max of pick and non pick.
    return max(pick,nonpick);
}
    
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    return maxsum(nums,n-1);
}

/*
TC:O(2^N)
SC:O(N)  recursion stack space
*/

/*
Approach-2 Memoization

--Just declare dp and use that

*/

#include<bits/stdc++.h>
using namespace std;
int maxsum(vector<int> &nums,int idx,vector<int>&dp)
{
    if(idx==0) return nums[idx];
    if(idx<0) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int pick=0,nonpick=0;
     pick=maxsum(nums,idx-2,dp)+nums[idx];
     nonpick=maxsum(nums,idx-1,dp)+0;
    
    return dp[idx]=max(pick,nonpick);
}
    
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int>dp(n,-1);
     return maxsum(nums,n-1,dp);
    
}
/*
TC:O(N)
SC:O(N)+O(N) vector space+recursion stack space
*/


/*
Approach-3 Tabulation

*/

// used only a single function because here we don't have any recursion.
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int>dp(n,-1);
    int pick=0,nonpick=0;
    dp[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        // for all values of i since we are picking we'll add nums[i]
        pick=nums[i];
        // this line is super imp if we have i-2 >=0 then pnly we'll add the dp[i-2] in pick otherwise it will only have its nums[i] value
        if(i-2>=0)pick+=dp[i-2];
        nonpick=dp[i-1]+0;
        dp[i]=max(pick,nonpick);
    }
    // dp[n-1] contains the ans as n-1 is last index in array
    return dp[n-1];
}
/*
TC:O(N)
SC:O(N) //for dp vector
*/

// Space optimization

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int pick,nonpick;
    int prev=nums[0],prev2=0,curr;
    for(int i=1;i<n;i++)
    {
        pick=nums[i];
        if(i>1) pick+=prev2;
        nonpick=prev+0;
        curr=max(pick,nonpick);
        prev2=prev;
        prev=curr;
    }
    return prev;
}

/*
TC:O(N)
SC:O(1)
*/