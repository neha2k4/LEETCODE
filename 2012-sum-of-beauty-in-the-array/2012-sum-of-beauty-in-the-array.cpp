class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size(),ans=0;
        vector<int>minright(n,nums[n-1]);

        for(int i=n-2;i>=0;i--)
        minright[i]=min(nums[i],minright[i+1]);

        int currmax = nums[0];
        for(int i=1;i<n-1;i++)
        {            
            if(currmax < nums[i] && minright[i+1]>nums[i])ans+=2;
            else if(nums[i - 1] < nums[i] &&  nums[i] < nums[i + 1])ans++;

            currmax=max(currmax,nums[i]);
        }
        
        return ans;
    }
};