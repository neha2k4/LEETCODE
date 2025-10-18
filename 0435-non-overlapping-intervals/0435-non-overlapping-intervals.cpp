class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int maxi=INT_MIN;
        sort(intervals.begin(),intervals.end(),[](vector<int> & a,vector<int> & b){return a[1]<b[1];});
        // cout<<intervals;
        int n=intervals.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(intervals[i][0]>=maxi)
            {
                maxi=intervals[i][1];
            }
            else{
                ans++;
            }
        }



        return ans;
        
    }
};