#include <iostream>
#include<limits.h>

#define R 3
#define C 3

using namespace std;

int min(int a, int b, int c) {
    return a < b ? a : (b < c) ? b : c;
}

//Dynamic Programming
int minCostUsingDP(int cost[R][C], int m, int n) {
    int i, j;

    // Instead of following line, we can use int tc[m+1][n+1] or
    // dynamically allocate memory to save space. The following line is
    // used to keep te program simple and make it working on all compilers.
    int tc[R][C];

    tc[0][0] = cost[0][0];

    /* Initialize first column of total cost(tc) array */
    for (i = 1; i <= m; i++)
        tc[i][0] = tc[i - 1][0] + cost[i][0];

    /* Initialize first row of tc array */
    for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j - 1] + cost[0][j];

    /* Construct rest of the tc array */
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tc[i][j] = min(tc[i - 1][j - 1], tc[i - 1][j], tc[i][j - 1]) + cost[i][j];

    return tc[m][n];
}

/* Returns cost of minimum cost path from (0,0) to (m, n) in mat[R][C]*/
//using Recurssion

int minCost(int cost[R][C], int m, int n) {
    if (n < 0 || m < 0)
        return INT_MAX;
    else if (m == 0 && n == 0)
        return cost[m][n];
    else
        return cost[m][n] + min(minCost(cost, m - 1, n - 1),
                                minCost(cost, m - 1, n),
                                minCost(cost, m, n - 1));
}

int main() {
    int cost[R][C] = {{1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3}};

    cout << minCost(cost, 2, 2);
//    cout << minCostUsingDP(cost, 2, 2);
    return 0;
}