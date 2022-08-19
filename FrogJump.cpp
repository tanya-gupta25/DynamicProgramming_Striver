//  Approach -1 Recursion

#include<bits/stdc++.h>
using namespace std;

int jumps(vector<int> &heights,int idx,int n)
{
    if(idx==0) return 0; //if frog is on stair 0 then frog can't jump anymore so energy released is 0
    
    int first=INT_MAX,second=INT_MAX;
    // a frog can jump either 1 or 2 stair so if he jumped 1 stair then energy released will be heights[idx]-heights[idx-1]  and we will check of idx-1>=0 becoz if its not then we will get out of bounds index
    if(idx-1>=0)first=jumps(heights,idx-1,n)+abs(heights[idx]-heights[idx-1]);
    // if frog jump 2 stairs then this will be the case
    if(idx-2>=0)second=jumps(heights,idx-2,n)+abs(heights[idx]-heights[idx-2]);
    
    int ans=min(first,second);
    return ans;
}
int frogJump(int n, vector<int> &heights)
{
    // our indexes are till size-1 so we will pass n-1 in array becoz n is not accessible
    return jumps(heights,n-1,n);
}

/*
Time Complexity:O(2^N)
Space Complexity: O(N) because of recursion stack space
*/


//  Approach -2 Memoization

#include<bits/stdc++.h>
using namespace std;

int jumps(vector<int> &heights,int idx,int n,vector<int>&dp)
{
    if(idx==0) return 0;
    if(dp[idx]!=-1 ) return dp[idx];  //check if dp already contains that value then return it
    int first=INT_MAX,second=INT_MAX;
    if(idx-1>=0)first=jumps(heights,idx-1,n,dp)+abs(heights[idx]-heights[idx-1]);
    if(idx-2>=0)second=jumps(heights,idx-2,n,dp)+abs(heights[idx]-heights[idx-2]);
    
    return dp[idx]=min(first,second);// store the ans in dp of that particular index
   
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n,-1); //initialize dp
    return jumps(heights,n-1,n,dp);
}

/*
Time Complexity:O(N)
Space Complexity: O(N) because of recursion stack space & vector 
*/


//  Approach -3 Tabulation

#include<bits/stdc++.h>
using namespace std;
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n,-1);
    int first=INT_MAX,second=INT_MAX;
    dp[0]=0; //if frog is on stair 0 then frog can't jump anymore so energy released is 0
    for(int i=1;i<n;i++)
    {
         first=dp[i-1]+abs(heights[i]-heights[i-1]);
        if(i-2>=0) second=dp[i-2]+abs(heights[i]-heights[i-2]);
        
        dp[i]=min(first,second);
    }
    return dp[n-1];
}

/*
Time Complexity:O(N)
Space Complexity: O(N) because of vector
*/

// Approach -4 Space Optimization

#include<bits/stdc++.h>
using namespace std;
int frogJump(int n, vector<int> &heights)
{
    int prev=0,prev2=0,curr; //prev is i-1 and prev2 is i-2
    int first=INT_MAX,second=INT_MAX;
    for(int i=1;i<n;i++)
    {
        // in first we added prev becoz we know frog will jump 1 step so we have to add i-1 that will be prev
        first=prev+abs(heights[i]-heights[i-1]);
        if(i>=2)second=prev2+abs(heights[i]-heights[i-2]);
        
        curr=min(first,second);
        prev2=prev;
        prev=curr;
    }
    return prev;
}

/*
Time Complexity: O(N)
Space Complexity: O(1) 
*/