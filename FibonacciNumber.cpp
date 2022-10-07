/*
Approach-1 Recursion
*/

class Solution {
    public int fib(int n) {
        if(n==0 || n==1) return n;
        return fib(n-1)+fib(n-2);
    }
}

/*
TC: O(2^N)
SC: O(N)
*/

/*
Approach-2 Memoization
*/
class Solution {
public:
    
    int fibonacci(int n, vector<int>&dp)
    {
        if(n==0 || n==1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]= fibonacci(n-1,dp)+fibonacci(n-2,dp);
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return fibonacci(n,dp);
    }
};
/*
TC: O(N)
SC: O(N)+O(N) {dp space + recursion stack space}
*/

/*
Approach-3 Tabulation
*/

class Solution {
public:
    int fib(int n) {
        int dp[n+1]; //need one extra block(0--n ==n+1 size block)
        if(n==0 || n==1) return n;
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
/*
TC:O(N)
SC:O(N)
*/

/*
Approach-4 Space Optimization
*/
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1) return n;
        int prev=1,prev2=0,curr;
        for(int i=2;i<=n;i++)
        {
            curr=prev+prev2;
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