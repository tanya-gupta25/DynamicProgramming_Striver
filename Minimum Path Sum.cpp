/*
Approach 1- Recursion
*/

/*
IMP NOTE : We've added or return 1e9(INT_MAX) so that the value in up or left becomes max value and the whole path gets cancel anyway because we'll always take min of both in this ques

*/

#include<bits/stdc++.h>
using namespace std;

int path(int i,int j,vector<vector<int>> &grid)
{
    if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return 1e9; // return the max value if index doesn't exist so the whole path will not be considered, if we would have used return 0 then this path would have been considered & we dont want it since it's wrong path
    int up=grid[i][j]+path(i-1,j,grid); //add the value of cell and go for upper cell
    int left=grid[i][j]+path(i,j-1,grid);
    
    return min(left,up); //since we want min path sum so will find min of both left and up
}
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    return path(n-1,m-1,grid);
}

/*
TC: O(2*(m*n))
SC: O((m-1)+(n-1))
*/


/*
Approach 2- Memoization
*/

#include<bits/stdc++.h>
using namespace std;

int path(int i,int j,vector<vector<int>> &grid,vector<vector<int>>&dp)
{
    if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=grid[i][j]+path(i-1,j,grid,dp);
    int left=grid[i][j]+path(i,j-1,grid,dp);
    
    return dp[i][j]= min(left,up);
}
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return path(n-1,m-1,grid,dp);
}

/*
TC: O(M*N)
SC:O(M*N)+O((m-1)+(n-1))
*/


/*
Approach 3- Tabulation
*/

#include<bits/stdc++.h>
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    
    int dp[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) dp[i][j]=grid[i][j];
            else
            {
                int up=grid[i][j];
                if(i>0) up+=dp[i-1][j];
                else up+=1e9;
                
                int left=grid[i][j];
                if(j>0) left+=dp[i][j-1];
                else left+=1e9;
                dp[i][j]=min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}

/*
TC: O(M*N)
SC:O(M*N)
*/


/*
Approach 4 - Space Optimization
*/

#include<bits/stdc++.h>
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    
    vector<int>prev(m,0);
    for(int i=0;i<n;i++)
    {
        vector<int>temp(m,0);
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) temp[j]=grid[i][j];
            else
            {
                int up=grid[i][j]; //since we want path sum thereby we'll add the value of the cell
                /*
                Here in up we have checked if i>0 then only we'll add prev[j] otherwise not becoz since
                 in this ques we're considering the sum of the path we're taking , so when i=0 then there will be 
                 no prev available and mostly if we say then at i=0 prev will be on i=-1 (which doesn't exist) hence for 
                 i=0 we'll not add prev[j]

                -- In unique paths ques we wrote the same thing but we haven't checked i>0 for up becoz in that for i=0 whole prev already 
                contains 0 at every index , and value 0 means path not considered, in unique path we had concept of return 0(path not considered) & return 1(path consider) 
                */
                if(i>0) up+=prev[j];
                else up+=1e9;   // will add the max value so that it will not be considered becoz we want min
                int left=grid[i][j];
                if(j>0) left+=temp[j-1];
                else left+=1e9;
                
                temp[j]=min(up,left);
            }
        }
        prev=temp;
    }
    return prev[m-1];
}

/*
TC: O(M*N)
SC:O(N)
*/