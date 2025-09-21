#define ll long long 
#define vll vector<ll>
#define vi vector<int>



class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vll pref(n+1,0);
        for(int i=1;i<=n;i++)
        {
            pref[i]=pref[i-1]+(ll)nums[i-1];
        
        }
        int res=INT_MAX;
        deque<int>dq;
        for(int i=0;i<=n;i++)
        {
            while(!dq.empty() && pref[i]-pref[dq.front()]>=k)
            {
                res=min(res,i-(int)dq.front()),dq.pop_front();
            }
            while(!dq.empty() && pref[i]<=pref[dq.back()]){
                dq.pop_back();

            }
            dq.push_back(i);
        }
        return res==INT_MAX ? -1:res;
        
        
    }
};



