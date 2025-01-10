class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long answer=0;
        int temp=0;
        for(int i=0; i<n; i++){
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int temp=0;
        for(int j=i; j<n; j++){
            temp=nums[j];
            maxi=max(maxi,temp);
            mini=min(mini,temp);
            answer+=maxi-mini;
        }
        }
        return answer;
    }
};