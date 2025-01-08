class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        long long l=0,r=0,ct=0,ans=0;
        sort(nums.begin(),nums.end());
        while(r<n)
        {
         ans+=nums[r];
         if(nums[r]*(r-l+1)>ans+k)
         {
            ans-=nums[l];
            l++;
         }
         ct=max(ct,r-l+1);
         r++;
        }
        return ct;
        }
};