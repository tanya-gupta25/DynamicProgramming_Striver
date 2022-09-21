/*
Approach1 - Recursion
*/

#include <bits/stdc++.h> 
using namespace std;

int paths(int i,int j)
{
    if(i==0 && j==0) return 1;
    
    if(i<0 || j<0) return 0;
    
    int up=0,left=0;
    
    up=paths(i-1,j);
    left=paths(i,j-1);
    
    return up+left;
}

int uniquePaths(int m, int n) {
	return paths(m-1,n-1);
}

/*
TC: O(2^(m*n))  becoz for every m*n we will calculate 2 values(up,left) so 2*2*2*2...
SC: O((n-1)+(m-1)) becoz max recursion will call for these operation

*/

/*
Approach2 - Memoization
*/

#include <bits/stdc++.h> 
using namespace std;

int paths(int i,int j,vector<vector<int>>&dp)
{
    if(i==0 && j==0) return 1;
    
    if(i<0 || j<0) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    int up=0,left=0;
    
    up=paths(i-1,j,dp);
    left=paths(i,j-1,dp);
    
    return dp[i][j]= up+left;
}

int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
	return paths(m-1,n-1,dp);
}

/*
TC: O(m*n) because we're now computing only m*n operations as operations which are computed are already stored in dp
SC: O(m*n)+O((m-1)+(n-1))  for dp m*n space and rest for recursion
*/

/*
Approach-3 Tabulation

*/

#include <bits/stdc++.h> 
using namespace std;
int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0) dp[i][j]=1;
            else
            {
                int up=0,left=0;
                if(i>0) up=  dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
    }
    return dp[m-1][n-1];
}

/*
TC: O(M*N)
SC: O(M*N)
*/


/*
Approach-4 Space Optimization

*/

#include <bits/stdc++.h> 
using namespace std;
int uniquePaths(int m, int n) {
    vector<int>prev(n,0);
    
    for(int i=0;i<m;i++)
    {
        vector<int>temp(n,0);
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0) temp[j]=1;
            else
            {
                 temp[j]=prev[j];
                if(j>0) temp[j]+= temp[j-1];
            }
        }
        prev=temp;
    }
    return prev[n-1];
}

/*
TC: O(M*N)
SC: O(N)
*/