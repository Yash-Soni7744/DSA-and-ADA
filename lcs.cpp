#include <iostream>
#include <string>
using namespace std;

// Function to find the length of the longest common subsequence
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();

    // Create a table to store lengths of LCS for each substring
    int dp[m + 1][n + 1];

    // Initialize the table
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = 0; // Base case: if either string is empty, LCS length is 0
            else if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1; // If characters match, increment LCS length
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Otherwise, take maximum of LCS lengths without the current characters
        }
    }

    // Return the length of LCS
    return dp[m][n];
}

int main() {
    string text1 = "AGGTAB";
    string text2 = "GXTXAYB";

    // Find and print the length of LCS
    cout << "Length of Longest Common Subsequence: " << longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
