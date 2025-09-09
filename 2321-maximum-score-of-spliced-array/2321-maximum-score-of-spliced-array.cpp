
// We are given two arrays. We need to return the maximized sum.

// To maximize the sum of array, we can swap contigous subarrays to maximize the sum of one array. ie. final_max_sum = original_array_sum + extra_benefit.

// Now extra_benefit can be calculated as -->
// we would make an vector and there we need to store bi - ai. And now when we have got a vector which contains our extra_benefit as answer, 
// we apply kadane algo to the vector to find largest sum contigous subarray. So, extra_benefit = maximum sum contigous subarray. 
// And now we can return final_max_sum = original_array_sum + extra_benefit.

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
    // <--------- Calculating sum of elements ------->
        long long sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        long long sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        
        vector<int> v(nums1.size(),0);
        vector<int> v1(nums1.size(),0);
        
    // <------------ Making difference/ extra_benefits vector --------->
        for(int i = 0; i < nums1.size(); i++){
            v[i] = nums2[i] - nums1[i];
        }
        for(int i = 0; i < nums2.size(); i++){
            v1[i] = nums1[i] - nums2[i];
        }
        
    // <---------- Applying kadane's algo on both vectors to find maximum sum contigous subarray -------> 
        int ans = 0, temp = 0;
        for(int i = 0; i < v.size(); i++){
            temp = max(v[i], temp+v[i]);
            ans = max(temp, ans);
        }
        temp = 0;
        int ans1 = 0;
        for(int i = 0; i < v.size(); i++){
            temp = max(v1[i], temp+v1[i]);
            ans1 = max(temp, ans1);
        }
        
        return max(sum1 + ans, sum2 + ans1);// return max(sum(A)+extra_benefits(A), sum(B)+extra_benefits(B) )
    }
};
