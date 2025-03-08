class Solution {
public:
    pair<int, int> max_min_index(const vector<int>& nums) {
        int max_idx = 0, min_idx = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[max_idx]) max_idx = i;
            if (nums[i] < nums[min_idx]) min_idx = i;
        }
        return {max_idx, min_idx};
    }

    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        auto [maxi, mini] = max_min_index(nums);
        int x = min(maxi, mini), y = max(maxi, mini);
        return min({y + 1, n - x, x + 1 + n - y});
    }
};