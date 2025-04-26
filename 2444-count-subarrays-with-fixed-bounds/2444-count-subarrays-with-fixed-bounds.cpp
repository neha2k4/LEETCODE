class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int minkPosition=-1;
        int maxkPosition=-1;
        int culpritIdx=-1;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=minK && nums[i]<=maxK)
            {
                if(nums[i]==minK)
                {
                    minkPosition=i;
                }
                if(nums[i]==maxK)
                {
                    maxkPosition=i;
                }
                int smaller=min(minkPosition,maxkPosition);
                int temp=smaller-culpritIdx;
                if(temp<=0)
                {
                    temp=0;
                }
                ans+=temp;

            }
            else{
                culpritIdx=i;
            }
          

        }
        return ans;
    }
};