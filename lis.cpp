#include <iostream>
#include <vector>
using namespace std;

// Function to find the length of the longest increasing subsequence
int longestIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    // Create a table to store lengths of LIS ending at each index
    vector<int> dp(n, 1);

    // Traverse the array from left to right
    for (int i = 1; i < n; ++i) {
        // For each element, compare it with all previous elements
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                // If current element is greater than previous element, update LIS length
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum LIS length
    int maxLIS = 1;
    for (int i = 0; i < n; ++i) {
        maxLIS = max(maxLIS, dp[i]);
    }

    return maxLIS;
}

int main() {
    // Example input array
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60};

    // Find and print the length of LIS
    cout << "Length of Longest Increasing Subsequence: " << longestIncreasingSubsequence(nums) << endl;

    return 0;
}
