class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans(n);
        int max = *max_element(candies.begin(), candies.end());
        n = 0;
        for (int i : candies) {
            ans[n++] = (i + extraCandies) >= max ? true : false;
        }
        return ans;
    }
};