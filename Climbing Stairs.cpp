/*
Approach-1 Recursion
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        //here if we can jump 1 or 2 stairs at a time , so even if we reached n=0 or 1 then it will be counted as 1 jump hence for n=0 return 1
        return climbStairs(n-1)+climbStairs(n-2);
    }
};

/*
TC: O(2^N)
SC: O(N)
*/

/*
Approach-2 Memoization(Top-down)
*/
class Solution {
public:
    int stairs(int n,vector<int>&dp)
    {
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]= stairs(n-1,dp)+stairs(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return stairs(n,dp);
    
    }
};

/*
TC: O(N)
SC: O(N)+O(N)
*/

/*
Approach-3 Tabulation(Bottom Up)
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        
        vector<int>dp(n+1);
        dp[0]=dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

/*
TC: O(N)
SC: O(N)
*/

/*
Approach-4 Space Optimization
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        
        int prev2=1,prev=1,curr;
        
        for(int i=2;i<=n;i++)
        {
            curr=prev2+prev;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
/*
TC: O(N)
SC: O(1)
*/