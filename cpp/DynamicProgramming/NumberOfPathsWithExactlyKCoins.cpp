// http://www.geeksforgeeks.org/number-of-paths-with-exactly-k-coins/

/* Input:  k = 12
    mat[][] = { {1, 2, 3},
                {4, 6, 5},
                {3, 2, 1}
              };
Output:  2
There are two paths with 12 coins
1 -> 2 -> 6 -> 2 -> 1
1 -> 2 -> 3 -> 5 -> 1*/


#include <bits/stdc++.h>
#define R 3
#define C 3
#define MAX_K 1000
using namespace std;

int dp[R][C][MAX_K];

int pathCountDPRecDP(int mat[][C], int m, int n, int k)
{
    // Base cases
    if (m < 0 || n < 0) return 0;
    if (m==0 && n==0) return (k == mat[m][n]);

    // If this sub-problem is already solved
    if (dp[m][n][k] != -1) return dp[m][n][k];

    // (m, n) can be reached either through (m-1, n) or through (m, n-1)
    dp[m][n][k] = pathCountDPRecDP(mat, m-1, n, k-mat[m][n]) + pathCountDPRecDP(mat, m, n-1, k-mat[m][n]);

    return dp[m][n][k];
}

// This function mainly initializes dp[][][] and calls
// pathCountDPRecDP()
int pathCountDP(int mat[][C], int k)
{
    memset(dp, -1, sizeof dp);
    return pathCountDPRecDP(mat, R-1, C-1, k);
}

// Driver Program to test above functions
int main()
{
    int k = 12;
    int mat[R][C] = { {1, 2, 3},
                      {4, 6, 5},
                      {3, 2, 1}
    };
    cout << pathCountDP(mat, k);
    return 0;
}