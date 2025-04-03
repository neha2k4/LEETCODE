class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        vector<vector<long long>> dp(k + 1, vector<long long>(nums.size() + 1, 0));

        for (int i = 1; i <= k; i++) {
            long long maxSum = LLONG_MIN/2;
            long long curr = LLONG_MIN/2;
            long long multiplier = (i % 2 == 1) ? (k + 1 - i) : (i - 1 - k);

            for (int j = i - 1; j < nums.size(); j++) {
                curr = max(curr + nums[j] * multiplier, dp[i - 1][j] + nums[j] * multiplier);
                maxSum = max(maxSum, curr);
                dp[i][j + 1] = maxSum;
            }
        }

        return dp[k][nums.size()];
    }
};