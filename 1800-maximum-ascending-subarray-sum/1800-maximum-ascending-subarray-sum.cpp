class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        
        int cnt=nums[0];
        int maxi=max(INT_MIN,cnt);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                cnt+=nums[i];
                maxi=max(maxi,cnt);

            }
            else{
                cnt=nums[i];
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
        
    }
};