// Ninja's Training

/*
Approach-1 Recursion

*/

#include <bits/stdc++.h>
using namespace std;

int training(int day, int last, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }

    int maxi = 0, score = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            score = points[day][i] + training(day - 1, i, points);
            maxi = max(maxi, score);
        }
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    //n-1 means we are on last day means last row , and 3 means we havent performed any task means last is 3
    return training(n - 1, 3, points);
}

/*
    TC: O(N*4) *3 -- for loop will run from 0->3
    SC:O(N)
*/

/*
Approach-2 Memoization

--Just declare dp and use that

*/

#include <bits/stdc++.h>
using namespace std;

int training(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxi = 0, score = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            score = points[day][i] + training(day - 1, i, points, dp);
            maxi = max(maxi, score);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    /*
        Here we have used N*4(day*last) size dp array becoz we can have N days to perform activities but we can only have 
        4 values(last) of task (0,1,2,3) means 0-- 0th task is performed,1-- 1th task is performed,2-- 2th task is performed, 3- none of 
        task is performed,thereby maximum we need 4 columns that why N*4.
    */
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return training(n - 1, 3, points, dp);
}

/*
    TC: O(N*4) *3 -- for loop will run from 0->3
    SC:O(N)+O(N*4)
*/

/*
Approach-3 Tabulation

*/

#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int score = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], score);
                }
            }
        }
    }
    return dp[n - 1][3];
}
/*
    TC: O(N*4*3)
    SC:O(N*4)
*/

/*
Approach-4 Space Optimization

*/
#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int score = points[day][task] + prev[task];
                    temp[last] = max(temp[last], score);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}

/*
    TC: O(N*4*3)
    SC:O(4)
*/