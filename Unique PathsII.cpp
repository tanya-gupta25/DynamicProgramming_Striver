/*
Approach-1 Recursive
*/
class Solution {
public:
    
    int path(int i,int j,vector<vector<int>>& obstacleGrid)
    {
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        
        int up=path(i-1,j,obstacleGrid);
        int left=path(i,j-1,obstacleGrid);
        return up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        return path(n-1,m-1,obstacleGrid);
    }
};

/*
TC:O(2^(m*n))
SC:O((m-1)+(n-1))

*/

/*
Approach 2 Memoization
*/

class Solution {
public:
    
    int path(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp)
    {
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up=path(i-1,j,obstacleGrid,dp);
        int left=path(i,j-1,obstacleGrid,dp);
        return dp[i][j]= up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return path(n-1,m-1,obstacleGrid,dp);
    }
};

/*
TC:O(M*N)
SC:O(M*N)+O((m-1)+(n-1))

*/

/*
Approach-3 Tabulation
*/

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    
    int dp[n][m];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i>=0 && j>=0 && mat[i][j]==-1) dp[i][j]=0;
            else if(i==0 && j==0) dp[i][j]=1;
            else
            {
                int up=0,left=0;
               if(i>0)  up=dp[i-1][j];
               if(j>0)  left=dp[i][j-1];
                dp[i][j]=(up+left)%1000000007;
            }
        }
    }
    return (dp[n-1][m-1])%1000000007;
}

/*
TC: O(M*N)
SC: O(M*N)

*/

/*
Approach-4 Space Optimization
*/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        /* for computing the curr row we just need prev row to store our ans , so we'll make a vector for curr and prev with the size of no of columns present
        and for every new row like i=0 then i=1..so on we'll calculate the whole curr for no of cols(j-0 to m)
        */
        vector<int>prev(m,0);  //specify how many columns a row have 
        for(int i=0;i<n;i++)
        {
            vector<int>cur(m,0);
            for(int j=0;j<m;j++)
            {
                if(i>=0 && j>=0 && obstacleGrid[i][j]==1) cur[j]=0; //this is one diff condition that if we got any obstacle then we'll not move forward
                else if(i==0 && j==0) cur[j]=1; //this is our destination so it'll be a path
                else
                {
                     cur[j]=prev[j];  //for calculating curr we need up and left so it is the up value which will be on same col
                    if(j>0) cur[j]+=cur[j-1]; //this is our left value which we'll add if j>0
                }
            }
            prev=cur;//lastly store the cur in prev for next computation & we'll calculate cur again
        }
        return prev[m-1]; //return the last index of prev
    }
};

/*
TC:O(M*N)
SC:O(M)

*/