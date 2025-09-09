class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int> mp;
        int maxi = INT_MIN;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == key){
                mp[nums[i+1]]++;
                maxi = max(maxi,mp[nums[i+1]]);
            }
        }
        if(maxi == INT_MIN)
            return -1;
        for(auto x:mp){
            if(maxi == x.second)
                return x.first;
        }
        return -1;
    }
};