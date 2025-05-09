class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int i=0, j=0;
        int ans=0;
        while(j<n){
            // for range intersection, [max value at i >= min value at j]
            while(nums[i]+k < nums[j]-k && i<=j) i++;
            ans=max(ans,j-i+1);
            j++;
        }
        
        return ans;
    }
};