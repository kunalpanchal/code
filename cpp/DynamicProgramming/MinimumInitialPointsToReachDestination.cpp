//http://www.geeksforgeeks.org/minimum-positive-points-to-reach-destination/

/* Input: points[m][n] = { {-2, -3,   3},
                        {-5, -10,  1},
                        {10,  30, -5}
                      };
Output: 7
Explanation:
7 is the minimum value to reach destination with
positive throughout the path. Below is the path.

(0,0) -> (0,1) -> (0,2) -> (1, 2) -> (2, 2)

We start from (0, 0) with 7, we reach(0, 1)
with 5, (0, 2) with 2, (1, 2) with 5, (2, 2)
with and finally we have 1 point (we needed
greater than 0 points at the end). */

// C++ program to find minimum initial points to reach destination

#include<iostream>
#include <stdlib.h>

#define R 3
#define C 3

using namespace std;

int minInitialPoints(int points[][C]) {
    // dp[i][j] represents the minimum initial points player
    // should have so that when starts with cell(i, j) successfully
    // reaches the destination cell(m-1, n-1)
    int dp[R][C];
    int m = R, n = C;

    // Base case
    dp[m - 1][n - 1] = points[m - 1][n - 1] > 0 ? 1 : abs(points[m - 1][n - 1]) + 1;

    // Fill last row and last column as base to fill
    // entire table
    for (int i = m - 2; i >= 0; i--)
        dp[i][n - 1] = max(dp[i + 1][n - 1] - points[i][n - 1], 1);
    for (int j = n - 2; j >= 0; j--)
        dp[m - 1][j] = max(dp[m - 1][j + 1] - points[m - 1][j], 1);

    // fill the table in bottom-up fashion
    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            int min_points_on_exit = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = max(min_points_on_exit - points[i][j], 1);
        }
    }

    for (int i = 0; i <m; i++) {
        for (int j =0;j<n;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][0];

}

// Driver Program
int main() {

    int points[R][C] = {{-2, -3,  3},
                        {-5, -10, 1},
                        {10, 30,  -5}
    };
    int points1[R][C] = {{-2, -3,  -100},
                        {-5, -100, 5},
                        {10, 20,  -15}
    };
    cout << "Minimum Initial Points Required: "
         << minInitialPoints(points1);
    return 0;
}