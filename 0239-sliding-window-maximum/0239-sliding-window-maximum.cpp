class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        ans.reserve(n - k + 1);

        deque<int> dq;

        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};


// BruteForceApproach
//  class Solution {
//  public:
//      vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//          int n = nums.size();
//          list<int> st;
//          for (int i = 0; i + k <= n; i++) {
//              int maxi = nums[i];
//              for (int j = i; j < i + k; j++) {
//                  maxi = max(maxi, nums[j]);
//              }
//              st.push_back(maxi);
//          }
//          return vector<int>(st.begin(), st.end());
//      }
//  };