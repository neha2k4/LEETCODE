class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
           int n = nums.size(); 
           int leftmax = nums[0];
           int max_so_far = nums[0];
           int index =0;
           for(int i=1;i<n;i++){
                if(nums[i]<leftmax){
                    index = i;
                    leftmax = max_so_far;
                }
                else{
                      max_so_far = max(max_so_far, nums[i]);
                }
           }
        return index+1;
    }
};