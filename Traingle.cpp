
/*
Approach-1 Recurisve
*/

class Solution {
public:
    
    int paths(int i,int j,vector<vector<int>>& triangle)
    {
        int n=triangle.size();
        
        if(i==n-1) return triangle[n-1][j];

        int down=paths(i+1,j,triangle)+triangle[i][j];
        int diag=paths(i+1,j+1,triangle)+triangle[i][j];
        
        return min(diag,down);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return paths(0,0,triangle);
    }
};

/*
TC:O(2*(N*N))
SC: O(N) -- max number of rows 
*/


/*
Approach-2 Memoization
*/

class Solution {
public:
    
    int paths(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp)
    {
        int n=triangle.size();
        
        if(i==n-1) return triangle[n-1][j];

        if(dp[i][j]!=-1)return dp[i][j];
        int down=paths(i+1,j,triangle,dp)+triangle[i][j];
        int diag=paths(i+1,j+1,triangle,dp)+triangle[i][j];
        
        return dp[i][j]= min(diag,down);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return paths(0,0,triangle,dp);
    }
};

/*
TC: O(N*N)
SC: O(N)+O(N*N)
*/


/*
Approach-3 Tabulation
*/

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        int dp[n][n];

        /*
        We have wrote this for loop as our base case , since we know through recursion our base case will be i==n-1 because if we go down this then it will be out of bounds, so here also we store all the values of i=n-1 in dp and run a for loop for j=0->n becoz last row has max n columns , so for i=n-1, we will increase j and will store all values of last row

        Ques may arise why we need to do it? So ans is if we dont do it then when we need value of i+1 for i=n-1 down part then we can't access i=n hence we store value of last row so that they can be used for other rows.
        */
        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }
        /*
        Here , since we are already done with i=n-1 thereby we ill start i from n-2->0 and we now in 0th row we have 0 col, in 1st row we have 0th and 1st col so on..
        Hence in every row j is equal to i so j=i->0
        */
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(diagonal, down);
            }
        }
        return dp[0][0];
    }
};

/*
TC:O(N*N)
SC:O(N*N)  //dp is of n*n size, n rows n cols
*/


/*
Approach-4 Space Optimization
*/

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> frontrow(n, 0);

        for (int j = 0; j < n; j++)
        {
            frontrow[j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> currow(n, 0);
            for (int j = i; j >= 0; j--)
            {
                int down = triangle[i][j] + frontrow[j];
                int diagonal = triangle[i][j] + frontrow[j + 1];
                currow[j] = min(down, diagonal);
            }
            frontrow = currow;
        }
        return frontrow[0];
    }
};


/*
TC:O(N*N)
SC:O(N)
*/