/*
Approach-1 Recursion
*/

/*
The concept of this ques is completely same as "subset sum equal to k" 
the difference is only target is not given to us in the ques
Motive of ques is that we need to partition the equal subset sum , like if total sum of array is 10 
then we have to find subset whose sum will be 5 ,if we found one subset of sum =5 then ofcourse other subset will also be there tbhi toh sum 10 hoga na

--so if sum is odd(like 11) then equal half subset sum can't be possible so directly return false
--if sum is even then just put target=sum/2 and rest the whole code is of subset sum equal to k
*/
class Solution {
public:
    
    bool subset(int idx,int target,vector<int>& nums)
    {
        if(target==0) return true;
        if(idx==0) return (nums[0]==target);
        
        bool notake=subset(idx-1,target,nums);
        bool take=false;
        if(target>=nums[idx]) take=subset(idx-1,target-nums[idx],nums);
        
        return take||notake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        /*
            Find the sum of the array if sum is odd then return false because it can't be divided equally
            Else if sum is even then target=sum/2 and rest do the same as subset sum equal to k
        */
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        return subset(n-1,target,nums);
    }
};

/*
TC: O(2^N)
SC:O(N)
*/

/*
Approach-2 Memoization
*/

class Solution {
public:
    
    bool subset(int idx,int target,vector<int>& nums,vector<vector<int>>&dp)
    {
        if(target==0) return true;
        if(idx==0) return (nums[0]==target);
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool notake=subset(idx-1,target,nums,dp);
        bool take=false;
        if(target>=nums[idx]) take=subset(idx-1,target-nums[idx],nums,dp);
        
        return dp[idx][target]= take||notake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        int target=sum/2;
        return subset(n-1,target,nums,dp);
    }
};

/*
TC:O(N*target)
SC:O(N)+O(N*target)
*/

/*
Approach-3 Tabulation
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2!=0) return false;
        int targets=sum/2;
        vector<vector<bool>>dp(n,vector<bool>(targets+1,0));
        
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        if(nums[0]<=targets)  dp[0][nums[0]]=true;
        
        for(int idx=1;idx<n;idx++)
        {
            for(int target=1;target<=sum/2;target++)
            {
                bool notake=dp[idx-1][target];
                bool take=false;
                if(target>=nums[idx]) take=dp[idx-1][target-nums[idx]];
                dp[idx][target]=take||notake;
            }
        }
        return dp[n-1][targets];
        
    }
};

/*
TC:O(N*target)
SC:O(N*target)
*/

/*
Approach-4 Space Optimization
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2!=0) return false;
        int targets=sum/2;
        vector<bool>prev(targets+1,0),curr(targets+1,0);
        
        
        for(int i=0;i<n;i++)
        {
            prev[0]=curr[0]=true;
        }
        if(nums[0]<=targets)  prev[nums[0]]=true;
        
        for(int idx=1;idx<n;idx++)
        {
            for(int target=1;target<=sum/2;target++)
            {
                bool notake=prev[target];
                bool take=false;
                if(target>=nums[idx]) take=prev[target-nums[idx]];
                curr[target]=take||notake;
            }
            prev=curr;
        }
        return prev[targets];
        
    }
};
/*
TC:O(N*target)
SC:O(target)
*/







