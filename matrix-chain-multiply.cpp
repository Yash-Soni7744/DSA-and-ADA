#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printOptimalParentheses(const vector<vector<int>>& s, int i, int j);

void matrixChainOrder(const vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i < n - length + 1; ++i) {
            int j = i + length - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = m[i][k] + m[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    // Output the optimal parentheses
    cout << "Optimal Parentheses: ";
    printOptimalParentheses(s, 0, n - 1);
    cout << endl;

    // Output the minimum number of scalar multiplications
    cout << "Minimum Scalar Multiplications: " << m[0][n - 1] << endl;
}

void printOptimalParentheses(const vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "M" << i;
    } else {
        cout << "(";
        printOptimalParentheses(s, i, s[i][j]);
        printOptimalParentheses(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    vector<int> dimensions = {30, 35, 15, 5, 10, 20, 25};
    matrixChainOrder(dimensions);

    return 0;
}
