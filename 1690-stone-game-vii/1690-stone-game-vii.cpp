// OJ: https://leetcode.com/contest/weekly-contest-219/problems/stone-game-vii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int stoneGameVII(vector<int>& A) {
        int N = A.size();
        vector<int> sum(N + 1);
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + A[i];
        vector<vector<int>> dp(N, vector<int>(N));
        for (int len = 2; len <= N; ++len) {
            for (int i = 0; i <= N - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = max(sum[j + 1] - sum[i + 1] - dp[i + 1][j], sum[j] - sum[i] - dp[i][j - 1]);
            }
        }
        return dp[0][N - 1];
    }
};