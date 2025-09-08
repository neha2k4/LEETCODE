class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq{0}; // store index of `nums` elements, elements is in decreasing order, the front is the maximum element.
        for (int i = 1; i < n; ++i) {
            // nums[i] = max(nums[i-k], nums[i-k+1], .., nums[i-1]) + nums[i] = nums[dq.front()] + nums[i]
            nums[i] = nums[dq.front()] + nums[i];

            // Add nums[i] to our deque
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back(); // Eliminate elements less or equal to nums[i], which will never be chosen in the future
            dq.push_back(i);

            // Remove if the last element is out of window size k
            if (i - dq.front() >= k) dq.pop_front();
        }
        return nums[n - 1];
    }
};