class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = INT_MIN;
        int ind = -1;

        // Find max element and its index
        for(int n = 0;n<nums.size(); n++){
            if(nums[n]>max){
                max = nums[n];
                ind = n;
            }
        }
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==max) continue; 
            if(nums[i]>max/2){
                return -1;
            }
        }

        return ind;
    }
};