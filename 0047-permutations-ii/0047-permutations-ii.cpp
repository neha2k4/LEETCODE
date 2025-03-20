class Solution {
public:
    int n;
    vector<vector<int>>ans;
    void permuteUniqueHelper(vector<int>& nums,int idx){
        if(idx==n){
            ans.push_back(nums);
            return;
        }
        unordered_map<int,bool>visited;
        for(int i=idx;i<n;i++){
            if(visited.find(nums[i])!=visited.end()){
                continue;
            }
            visited[nums[i]]=true;
            swap(nums[i],nums[idx]);
            permuteUniqueHelper(nums,idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        permuteUniqueHelper(nums,0);
        return ans;
    }
};