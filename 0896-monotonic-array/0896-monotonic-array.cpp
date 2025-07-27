class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n-1 && nums[i]==nums[i+1]){
            i++;
        }
        if(i==n-1){
            return true;
        }
        if(nums[i]<nums[i+1]){
            for(i=i+1;i<n;i++){
                if(nums[i]<nums[i-1]){
                    return false;
                }
            }
        }
        else{
             for(i=i+1;i<n;i++){
                if(nums[i]>nums[i-1]){
                    return false;
                }
            }
        }
        return true;
    }
};