/*
Approach 1 - Recursion
*/

/*
-- Here we can't take first and last element together so we will divide the whole array in two ways
-- first is use array from 0 to n-2 and other use array from 1 to n-1 then find max of both
-- for recursive and memoize we  will use 2 vectors method v1 will contain 0 to n-2 and v2 will contain 1 to n-1
-- for tabulation & optimization we have used left and right instead of 2 vectors

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int maxMoney(vector<int>&v,int idx)
    {
        if(idx==0) return v[idx]; //if its on i=0 then return the value of that house
        if(idx<0) return 0;
        
        int pick=0,nonpick=0;
        
        pick=v[idx]+maxMoney(v,idx-2);
        nonpick=0+maxMoney(v,idx-1);
        
        int ans=max(pick,nonpick);
        return ans;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>v1;
        vector<int>v2;
        for(int i=0;i<n;i++)
        {
            if(i!=0) v1.push_back(nums[i]); //contains from 1 to n-1
            if(i!=n-1) v2.push_back(nums[i]); //contains from 0 to n-2
        }
        return max(maxMoney(v1,v1.size()-1),maxMoney(v2,v2.size()-1));
    }
};

/*
Time Complexity:O(2^N)
Space Complexity: O(N)
*/


/*
Approach 2- Memoization
*/

class Solution {
public:
    int maxsum(vector<int>&v,vector<int>&dp,int idx)
    {
        if(idx==0) return v[0];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick=0,nonpick=0;
        pick=v[idx]+maxsum(v,dp,idx-2);
        nonpick=0+maxsum(v,dp,idx-1);
        return dp[idx]= max(pick,nonpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>v1,v2;
        vector<int>dp1(n,-1),dp2(n,-1);
        for(int i=0;i<n;i++)
        {
            if(i!=0) v1.push_back(nums[i]);
            if(i!=n-1)v2.push_back(nums[i]);
        }
        return max (maxsum(v1,dp1,n-2),maxsum(v2,dp2,n-2));
    }
};

/*
Time Complexity:O(N)
Space Complexity:O(N)
*/


/*
Approach 3 - Tabulation
*/

class Solution {
public:
    
    int maxMoney(vector<int>& nums,int left,int right,vector<int>&dp)
    {
        dp[0]=0; 
        /*
        we have used dp[0]=0 for two types of cases
        -- suppose from 1 to n-1 then ofcourse we cant use dp[0]=nums[0] becoz we're not taking index=0 here so we have to handle this base case hence for this condition dp [0] should be 0.
        --  from 0 to n-2 we will get this case to add dp[0] but it worked here because we have already took dp[0] in pick=nums[0/i] , so for every value of i we will pick the particular index even if we dont get into if conditionn
        */
        
        int pick=0,nonpick=0;
        for(int i=left;i<=right;i++)
        {
            // we have picked here every value of i even i-2 is less than 0 still we got every index considered in ans thats why dp[0] will be 0 here
            pick=nums[i];
            if(i-2>=0) pick+=dp[i-2];
            if(i-1>=0)nonpick=0+dp[i-1];
            
            dp[i]=max(pick,nonpick);
        }
        return dp[right];//becoz it contains the last index which is accessible and has answer
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(maxMoney(nums,0,n-2,dp),maxMoney(nums,1,n-1,dp));
    }
};

/*
Time Complexity:O(N)
Space Complexity:O(N)  //dp vector used + recursion stack space
*/


/*
Approach 4 - Space Optimization
*/

class Solution {
public:
    
    int maxMoney(vector<int>& nums,int left,int right)
    {
        int prev=0,prev2=0,curr;
        int pick=0,nonpick=0;
        
        for(int i=left;i<=right;i++)
        {
            pick=nums[i]+prev2;//prev2=i-2(general way) thats why
            nonpick=0+prev; // prev=i-1
            curr=max(pick,nonpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(maxMoney(nums,0,n-2),maxMoney(nums,1,n-1));
    }
};

/*
Time Complexity:O(N)
Space Complexity:O(N) // recursion space otherwise it's O(1)
*/