class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        map<int, int> mpp; 
        int l = 0, r = 0;  
        int maxi = 0;     

        while (r < n) {
            mpp[fruits[r]]++; 
            while (mpp.size() > 2) {
                mpp[fruits[l]]--; 
                if (mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++; 
            }
            maxi = max(maxi, r - l + 1);
            r++; 
        }
        return maxi;
    }
};