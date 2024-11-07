//time and space com = O(n*w)
//n = no. of items and w is maximum weight

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve 0-1 Knapsack using Dynamic Programming
int knapsackDP(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)); // DP table initialization

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Maximize by including or excluding the current item
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                // Current item cannot be included due to weight constraint
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value with the given weight capacity
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    vector<int> weights(n), values(n);
    cout << "Enter the weight and value for each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ":\n";
        cout << "Weight: ";
        cin >> weights[i];
        cout << "Value: ";
        cin >> values[i];
    }

    int maxValue = knapsackDP(W, weights, values, n);
    cout << "The maximum value in the knapsack is: " << maxValue << endl;

    return 0;
}
/*
Enter the number of items: 4
Enter the maximum weight capacity of the knapsack: 8
Enter the weight and value for each item:
Item 1:
Weight: 2
Value: 1
Item 2:
Weight: 3
Value: 2
Item 3:
Weight: 4
Value: 5
Weight: 5
Value: 6

The maximum value in the knapsack is: 8
*/