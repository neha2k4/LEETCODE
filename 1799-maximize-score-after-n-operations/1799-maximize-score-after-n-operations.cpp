class Solution {
    vector<int> dp;
private:
    int f(int k, int mask, vector<int>& nums){
        if(k==0) return 0;
        if(dp[mask]!=-1) return dp[mask];
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if((mask&(1<<i)) == 0) continue;
            for(int j=i+1; j<nums.size(); j++){
                if(mask&(1<<j)){
                    ans = max(ans, k*gcd(nums[i],nums[j])+f(k-1,mask^(1<<i)^(1<<j),nums));
                }
            }
        }
        return dp[mask] = ans;
    }
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int mask = (1<<n)-1;
        dp.resize(mask+1,-1);
        return f(n/2,mask,nums);
    }
};