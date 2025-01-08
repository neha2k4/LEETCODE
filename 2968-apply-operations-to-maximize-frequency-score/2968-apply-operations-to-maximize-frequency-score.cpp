class Solution {
public:
    // Function to calculate the sum of differences in a range [l, r] in the sorted 'nums' array
    long long findme(int l, int r, vector<int>& nums, vector<long long>& prefix) {
        int mid = (r + l) / 2;
        long long first = prefix[mid];

        // Adjusting the 'first' by subtracting the prefix sum till the left boundary 'l'
        if (l > 0) {
            first -= prefix[l - 1];
        }

        long long ans = (1LL * nums[mid] * (mid - l + 1)) - first;

        // Calculating the second part of the range (right side)
        long long second = prefix[r] - prefix[mid];
        ans += second - (1LL * nums[mid] * (r - mid));

        return ans;
    }
    
    // Function to find the maximum length of subarray satisfying the conditions
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(nums.size());

        // Calculating the prefix sum of the sorted 'nums' array
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                prefix[i] = nums[i];
            } else {
                prefix[i] = nums[i] + prefix[i - 1];
            }
        }

        int maxi = 0;

        // Iterating through each element to find the maximum length of subarray
        for (int i = 0; i < n; ++i) {
            int low = i;
            int high = n - 1;
            int ans = -1;

            // Binary search to find the right boundary of the subarray
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (findme(i, mid, nums, prefix) <= k) {
                    ans = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            // Update the maximum length found so far
            if (ans != -1) {
                maxi = max(maxi, ans - i + 1);
            }
        }
        return maxi;
    }
};

