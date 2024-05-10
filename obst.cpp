#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the cost of an Optimal Binary Search Tree
int optimalBSTCost(const vector<int>& keys, const vector<int>& freq) {
    int n = keys.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Initialize the diagonal values of dp table with frequencies
    for (int i = 0; i < n; ++i) {
        dp[i][i] = freq[i];
    }

    // Fill the dp table diagonally
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // Calculate the cost for each possible root
            for (int r = i; r <= j; ++r) {
                int cost = ((r > i) ? dp[i][r - 1] : 0) + ((r < j) ? dp[r + 1][j] : 0);

                dp[i][j] = min(dp[i][j], cost);
            }

            // Add frequencies in range [i, j]
            for (int k = i; k <= j; ++k) {
                dp[i][j] += freq[k];
            }
        }
    }

    // Return the cost of optimal BST
    return dp[0][n - 1];
}

int main() {
    // Example keys and their frequencies
    vector<int> keys = {10, 12, 20};
    vector<int> freq = {34, 8, 50};

    // Calculate and print the optimal cost of BST
    cout << "Optimal Cost of Binary Search Tree: " << optimalBSTCost(keys, freq) << endl;

    return 0;
}
