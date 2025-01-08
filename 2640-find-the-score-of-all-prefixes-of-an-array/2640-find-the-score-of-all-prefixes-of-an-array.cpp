class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        long long maxValue = nums[0];
        vector<long long> ans;
        long long value = maxValue + nums[0];
        ans.push_back(value);

        for (int i = 1; i < n; i++) {
            if (nums[i] > maxValue) maxValue = nums[i];
            value = ans.back() + maxValue + nums[i];
            ans.push_back(value);
        }
        return ans;
    }
};