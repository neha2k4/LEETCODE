class Solution {
public:
    #define ll long long
    int dp[2001][51];
    ll mod=1000000007;
    int find(int i,int prev1,vector<int> &nums)
    {
        if(i>=nums.size())
            return 1;
        if(dp[i][prev1]!=-1)
            return dp[i][prev1];
        ll res=0;    
        for(int ar1=0;ar1<=nums[i];ar1++)
        {
            if(i>0 && ar1<prev1)
               continue;
            if(i>0 && (nums[i]-ar1)>(nums[i-1]-prev1))
               continue;
            res=(res+find(i+1,ar1,nums))%mod;
        }    
        return dp[i][prev1]=res;    
    }
    int countOfPairs(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        return find(0,0,nums);
    }
};