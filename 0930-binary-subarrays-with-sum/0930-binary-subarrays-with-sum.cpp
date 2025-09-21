class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int> cnt;
        cnt[0]=1;
        int curr_sum=0;
        int total=0;
        for(int num : nums)
        {
            curr_sum+=num;
            if(cnt.find(curr_sum-goal)!=cnt.end())
            {
                total+=cnt[curr_sum-goal];

            }
            cnt[curr_sum]++;
        }
        return total;

        
    }
};