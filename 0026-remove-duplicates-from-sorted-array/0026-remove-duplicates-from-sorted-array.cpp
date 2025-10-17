class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for(int j=0;j<n;j++)
        {
            if(nums[j]>nums[i])
            {
                nums[i+1]=nums[j];
                i++;
            }
        }
        int k=i+1;
        return k;
        // int k=1;
        // for(int i=1;i<n;i++)
        // {
        //     if(nums[i]!=nums[i-1])
        //     {
        //         nums[k]=nums[i];
        //         k++;
        //     }
        // }
        // return k;
    }
};