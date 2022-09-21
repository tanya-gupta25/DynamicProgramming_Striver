/*
Approach-1 Recursion
*/

#include <bits/stdc++.h> 
using namespace std;
int path(vector<vector<int>> &matrix,int n,int i,int j)
{
    int m=matrix[0].size();
     if(j<0 || j>=m) return -1e9;
     if(i==n-1) return matrix[i][j];   
     
     int left=INT_MIN,down=INT_MIN,diag=INT_MIN;
    
     left=matrix[i][j]+path(matrix,n,i+1,j-1);
     down=matrix[i][j]+path(matrix,n,i+1,j);
     diag=matrix[i][j]+path(matrix,n,i+1,j+1);
    
    return max(left,max(down,diag));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size(),maxi=INT_MIN;
    int m=matrix[0].size();
    for(int col=0;col<m;col++)
    {
        maxi=max(maxi,path(matrix,n,0,col));
    }
    return maxi;
}

/*
TC: O(3^n);
SC:O(N)
*/


/*
Approach-2 Memoization
*/


#include <bits/stdc++.h> 
using namespace std;
int path(vector<vector<int>> &matrix,int n,int i,int j,vector<vector<int>>&dp)
{
    int m=matrix[0].size();
     if(j<0 || j>=m) return -1e9;
     if(i==n-1) return matrix[i][j];   
     if(dp[i][j]!=-1) return dp[i][j];
     int left=INT_MIN,down=INT_MIN,diag=INT_MIN;
    
     left=matrix[i][j]+path(matrix,n,i+1,j-1,dp);
     down=matrix[i][j]+path(matrix,n,i+1,j,dp);
     diag=matrix[i][j]+path(matrix,n,i+1,j+1,dp);
    
    return dp[i][j]= max(left,max(down,diag));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size(),maxi=INT_MIN;
    int m=matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int col=0;col<m;col++)
    {
        maxi=max(maxi,path(matrix,n,0,col,dp));
    }
    return maxi;
}

/*
TC: O(N*M);
SC:O(N)+O(N*M)
*/


/*
Approach-3 Tabulation
*/

#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size(),m=matrix[0].size();
    int dp[n][m];
    
    for(int last=0;last<m;last++)
    {
        dp[n-1][last]=matrix[n-1][last];
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            int left=matrix[i][j];
            if(j-1>=0) left+= dp[i+1][j-1];
            else left+=-1e9;
            int down=matrix[i][j]+dp[i+1][j];
            int diag=matrix[i][j];
            if(j+1<m) diag +=dp[i+1][j+1];
            else diag+=-1e9;
            dp[i][j]=max(left,max(down,diag));
        }
    }
    int maxi=INT_MIN;
    for(int first=0;first<m;first++)
    {
        maxi=max(maxi,dp[0][first]);
    }
    return maxi;
}

/*
TC: O(N*M)+O(M) -- for the last(first=0->m) for loop;
SC:O(N*M)
*/

/*
Approach 4- Space Optimization

*/
#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size(),m=matrix[0].size();
    vector<int>prev(m,0),curr(m,0);
    
    for(int first=0;first<m;first++)
    {
        prev[first]=matrix[0][first];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int left=matrix[i][j];
            if(j-1>=0) left+= prev[j-1];
            else left+= -1e9;
            
            int down=matrix[i][j]+prev[j];
            
            int diag=matrix[i][j];
            if(j<=m-2) diag+=prev[j+1];
            else diag+= -1e9;
            
            curr[j]=max(left,max(diag,down));
        }
        prev=curr;
    }
    int maxi=INT_MIN;
    for(int last=0;last<m;last++)
    {
        maxi=max(maxi,prev[last]);
    }
    return maxi;
}

/*
TC: O(N*M)+O(M) -- for the last(first=0->m) for loop;
SC:O(N)
*/


