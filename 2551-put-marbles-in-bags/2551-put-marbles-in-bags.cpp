class Solution {
public:
    long long putMarbles(vector<int>& nums, int k) {
        long long maxi=0,mini=0;

        vector<int>temp;
        for(int i=0;i<nums.size()-1;i++){
            temp.push_back(nums[i]+nums[i+1]);
        }

        sort(temp.begin(),temp.end());
        int n=temp.size();
        for(int i=0;i<k-1;i++){
            mini+=temp[i];
            maxi+=temp[n-1-i];
        }
        return maxi-mini;
    }
};