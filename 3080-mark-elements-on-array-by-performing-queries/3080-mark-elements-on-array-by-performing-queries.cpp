class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<long long> ans ;
        long long sum = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i],i});
            sum += nums[i];
        }
        int k;
        for(auto &i: queries){
            k = i[1];
            if(nums[i[0]]>0){
                sum -= nums[i[0]];
                nums[i[0]] *= -1;
            }
            while(!pq.empty() && k){
                if(pq.size()>0 && nums[pq.top().second] < 0){
                    pq.pop();
                    continue;
                }
                sum -= nums[pq.top().second];
                nums[pq.top().second] *= -1;
                pq.pop();
                k--;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};