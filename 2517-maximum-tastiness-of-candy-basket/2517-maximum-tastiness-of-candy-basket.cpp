class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin() , price.end());
        int n = price.size(), left = 0, right = price[n - 1] - price[0];
        while(left < right){
            int mid = (right + left + 1) / 2;
            int last = price[0], count = 1;
            for(int i = 1; i < n; ++i){
                if(price[i] - last >= mid){
                    if(++count == k) break;
                    last = price[i];
                }
            }
            if(count == k) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};